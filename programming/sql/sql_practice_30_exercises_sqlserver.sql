-- ======================================================================
-- SQL PRACTICE: 30 EXERCISES (SQL Server Edition)
-- Author: Generated for practice
-- Target: Microsoft SQL Server (T-SQL)
-- Tables:
--   customer(customer_id, customer_unique_id, customer_zip_code, customer_city, customer_state)
--   order_history(order_id, customer_id, order_status, purchase_time, approved_time,
--                 delivered_carrier_time, delivered_customer_time, estimated_delivery_time, payment_type)
--   order_item(order_id, order_item_id, product_id, seller_id, shipping_limit_date, amount, freight_value)
-- ======================================================================

-- ℹ️ Let's do excercise in paper first before do excercise in sql

/* =============================
   PART A – BASICS
   ============================= */

-- 1) List 10 customers
SELECT TOP 10 customer_id, customer_city, customer_state
FROM customer
ORDER BY customer_id;

-- 2) Delivered orders
SELECT order_id, customer_id, order_status, purchase_time
FROM order_history
WHERE order_status = 'delivered';

-- 3) Orders purchased in October 2017
SELECT order_id, customer_id, purchase_time
FROM order_history
WHERE purchase_time >= '2017-10-01'
  AND purchase_time < '2017-11-01';

-- 4) Top 5 order items by amount
SELECT TOP 5 order_id, order_item_id, amount
FROM order_item
ORDER BY amount DESC;

-- 5) Total freight cost
SELECT SUM(freight_value) AS total_freight_value
FROM order_item;

/* =============================
   PART B – JOINS
   ============================= */

-- 6) Latest purchase per customer
SELECT c.customer_id,
       c.customer_city,
       c.customer_state,
       MAX(o.purchase_time) AS last_purchase_time
FROM customer c
JOIN order_history o ON o.customer_id = c.customer_id
GROUP BY c.customer_id, c.customer_city, c.customer_state;

-- 7) Total amount per customer
SELECT c.customer_id,
       ISNULL(SUM(oi.amount), 0) AS total_amount
FROM customer c
LEFT JOIN order_history o ON o.customer_id = c.customer_id
LEFT JOIN order_item oi ON oi.order_id = o.order_id
GROUP BY c.customer_id;

-- 8) Number of orders by state
SELECT c.customer_state,
       COUNT(o.order_id) AS orders_cnt
FROM customer c
JOIN order_history o ON o.customer_id = c.customer_id
GROUP BY c.customer_state
ORDER BY orders_cnt DESC;

-- 9) Combine 3 tables
SELECT c.customer_id,
       o.order_id,
       o.order_status,
       oi.amount,
       oi.freight_value
FROM customer c
JOIN order_history o ON o.customer_id = c.customer_id
JOIN order_item oi ON oi.order_id = o.order_id;

-- 10) Top 5 customers by spend
SELECT TOP 5 c.customer_id,
       SUM(oi.amount + oi.freight_value) AS total_spend
FROM customer c
JOIN order_history o ON o.customer_id = c.customer_id
JOIN order_item oi ON oi.order_id = o.order_id
GROUP BY c.customer_id
ORDER BY total_spend DESC;

/* =============================
   PART C – GROUP BY / HAVING
   ============================= */

-- 11) Average item amount by payment_type
SELECT o.payment_type,
       AVG(oi.amount) AS avg_item_amount
FROM order_history o
JOIN order_item oi ON oi.order_id = o.order_id
GROUP BY o.payment_type
ORDER BY avg_item_amount DESC;

-- 12) Orders count & revenue per state
SELECT c.customer_state,
       COUNT(DISTINCT o.order_id) AS orders_cnt,
       SUM(oi.amount) AS revenue
FROM customer c
JOIN order_history o ON o.customer_id = c.customer_id
JOIN order_item oi ON oi.order_id = o.order_id
GROUP BY c.customer_state;

-- 13) States with revenue > 100000
SELECT c.customer_state,
       SUM(oi.amount) AS revenue
FROM customer c
JOIN order_history o ON o.customer_id = c.customer_id
JOIN order_item oi ON oi.order_id = o.order_id
GROUP BY c.customer_state
HAVING SUM(oi.amount) > 100000
ORDER BY revenue DESC;

-- 14) Average freight per seller
SELECT seller_id,
       AVG(freight_value) AS avg_freight
FROM order_item
GROUP BY seller_id
ORDER BY avg_freight DESC;

-- 15) Unique customers per state
SELECT customer_state,
       COUNT(DISTINCT customer_unique_id) AS unique_customers
FROM customer
GROUP BY customer_state
ORDER BY unique_customers DESC;

/* =============================
   PART D – SUBQUERY & CTE
   ============================= */

-- 16) Largest order per customer
WITH order_totals AS (
  SELECT o.customer_id, o.order_id, SUM(oi.amount) AS order_total
  FROM order_history o
  JOIN order_item oi ON oi.order_id = o.order_id
  GROUP BY o.customer_id, o.order_id
)
SELECT t.*
FROM order_totals t
WHERE t.order_total = (
  SELECT MAX(order_total)
  FROM order_totals tt
  WHERE tt.customer_id = t.customer_id
);

-- 17) Revenue by state, top state
WITH revenue_by_state AS (
  SELECT c.customer_state, SUM(oi.amount) AS revenue
  FROM customer c
  JOIN order_history o ON o.customer_id = c.customer_id
  JOIN order_item oi ON oi.order_id = o.order_id
  GROUP BY c.customer_state
)
SELECT TOP 1 *
FROM revenue_by_state
ORDER BY revenue DESC;

-- 18) Cancellation rate per state
WITH state_orders AS (
  SELECT c.customer_state,
         SUM(CASE WHEN o.order_status = 'canceled' THEN 1 ELSE 0 END) AS canceled_cnt,
         COUNT(*) AS total_cnt
  FROM customer c
  JOIN order_history o ON o.customer_id = c.customer_id
  GROUP BY c.customer_state
)
SELECT customer_state,
       canceled_cnt,
       total_cnt,
       ROUND(100.0 * canceled_cnt / NULLIF(total_cnt,0), 2) AS cancel_rate_pct
FROM state_orders
ORDER BY cancel_rate_pct DESC;

-- 19) Customers spending above average
WITH spend_by_customer AS (
  SELECT c.customer_id, SUM(oi.amount) AS total_spend
  FROM customer c
  JOIN order_history o ON o.customer_id = c.customer_id
  JOIN order_item oi ON oi.order_id = o.order_id
  GROUP BY c.customer_id
),
overall AS (
  SELECT AVG(total_spend) AS avg_spend FROM spend_by_customer
)
SELECT s.customer_id, s.total_spend
FROM spend_by_customer s, overall a
WHERE s.total_spend > a.avg_spend
ORDER BY s.total_spend DESC;

-- 20) Average delivery interval per state
SELECT c.customer_state,
       AVG(DATEDIFF(DAY, o.purchase_time, o.delivered_customer_time)) AS avg_delivery_days
FROM customer c
JOIN order_history o ON o.customer_id = c.customer_id
WHERE o.delivered_customer_time IS NOT NULL
GROUP BY c.customer_state
ORDER BY avg_delivery_days;

/* =============================
   PART E – WINDOW FUNCTIONS & CASE
   ============================= */

-- 21) Rank customers by spend
WITH spend AS (
  SELECT c.customer_id, SUM(oi.amount) AS total_spend
  FROM customer c
  JOIN order_history o ON o.customer_id = c.customer_id
  JOIN order_item oi ON oi.order_id = o.order_id
  GROUP BY c.customer_id
)
SELECT customer_id,
       total_spend,
       RANK() OVER (ORDER BY total_spend DESC) AS spend_rank
FROM spend
ORDER BY spend_rank;

-- 22) Top customer per state
WITH spend_state AS (
  SELECT c.customer_state, c.customer_id, SUM(oi.amount) AS total_spend
  FROM customer c
  JOIN order_history o ON o.customer_id = c.customer_id
  JOIN order_item oi ON oi.order_id = o.order_id
  GROUP BY c.customer_state, c.customer_id
),
ranked AS (
  SELECT *,
         ROW_NUMBER() OVER (PARTITION BY customer_state ORDER BY total_spend DESC) AS rn
  FROM spend_state
)
SELECT customer_state, customer_id, total_spend
FROM ranked
WHERE rn = 1
ORDER BY total_spend DESC;

-- 23) Segment customers by spend
WITH spend AS (
  SELECT c.customer_id, SUM(oi.amount) AS total_spend
  FROM customer c
  JOIN order_history o ON o.customer_id = c.customer_id
  JOIN order_item oi ON oi.order_id = o.order_id
  GROUP BY c.customer_id
)
SELECT customer_id,
       total_spend,
       CASE
         WHEN total_spend < 500 THEN 'Low'
         WHEN total_spend BETWEEN 500 AND 2000 THEN 'Medium'
         ELSE 'High'
       END AS segment
FROM spend;

-- 24) Cumulative revenue by state
WITH orders_with_amount AS (
  SELECT c.customer_state, CAST(o.purchase_time AS date) AS purchase_date, SUM(oi.amount) AS order_total
  FROM customer c
  JOIN order_history o ON o.customer_id = c.customer_id
  JOIN order_item oi ON oi.order_id = o.order_id
  GROUP BY c.customer_state, CAST(o.purchase_time AS date)
)
SELECT customer_state,
       purchase_date,
       order_total,
       SUM(order_total) OVER (PARTITION BY customer_state ORDER BY purchase_date ROWS UNBOUNDED PRECEDING) AS cum_revenue
FROM orders_with_amount
ORDER BY customer_state, purchase_date;

-- 25) On-time vs Late delivery
SELECT o.order_id,
       o.estimated_delivery_time,
       o.delivered_customer_time,
       CASE
         WHEN o.delivered_customer_time IS NULL THEN 'Unknown'
         WHEN o.delivered_customer_time > o.estimated_delivery_time THEN 'Late'
         ELSE 'On-time'
       END AS delivery_status
FROM order_history o;

/* =============================
   PART F – ADVANCED ANALYSIS
   ============================= */

-- 26) Average orders per customer per state
WITH orders_per_customer AS (
  SELECT c.customer_state, c.customer_id, COUNT(DISTINCT o.order_id) AS cnt
  FROM customer c
  JOIN order_history o ON o.customer_id = c.customer_id
  GROUP BY c.customer_state, c.customer_id
)
SELECT customer_state,
       AVG(CAST(cnt AS FLOAT)) AS avg_orders_per_customer
FROM orders_per_customer
GROUP BY customer_state
ORDER BY avg_orders_per_customer DESC;

-- 27) Avg approval latency (days)
SELECT AVG(DATEDIFF(DAY, purchase_time, approved_time)) AS avg_approval_latency
FROM order_history
WHERE approved_time IS NOT NULL;

-- 28) Busiest day
SELECT TOP 1 CAST(purchase_time AS date) AS order_date,
       COUNT(*) AS orders_cnt
FROM order_history
GROUP BY CAST(purchase_time AS date)
ORDER BY orders_cnt DESC;

-- 29) Payment type distribution
WITH pt AS (
  SELECT payment_type, COUNT(*) AS cnt
  FROM order_history
  GROUP BY payment_type
),
tot AS (
  SELECT SUM(cnt) AS total FROM pt
)
SELECT p.payment_type,
       p.cnt,
       ROUND(100.0 * p.cnt / t.total, 2) AS pct
FROM pt p CROSS JOIN tot t
ORDER BY pct DESC;

-- 30) State with highest late delivery rate
WITH delivery_flag AS (
  SELECT o.order_id, c.customer_state,
         CASE
           WHEN o.delivered_customer_time IS NULL THEN NULL
           WHEN o.delivered_customer_time > o.estimated_delivery_time THEN 1
           ELSE 0
         END AS is_late
  FROM order_history o
  JOIN customer c ON c.customer_id = o.customer_id
),
state_stats AS (
  SELECT customer_state,
         SUM(CASE WHEN is_late = 1 THEN 1 ELSE 0 END) AS late_cnt,
         COUNT(is_late) AS delivered_cnt
  FROM delivery_flag
  GROUP BY customer_state
)
SELECT TOP 1 customer_state,
       late_cnt,
       delivered_cnt,
       ROUND(100.0 * late_cnt / NULLIF(delivered_cnt,0), 2) AS late_rate_pct
FROM state_stats
ORDER BY late_rate_pct DESC;

-- ======================================================================
-- End of SQL Server version
-- ======================================================================
