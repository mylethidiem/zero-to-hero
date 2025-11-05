--- Hello
/*
Practice sql
*/

--- SELECT: display
SELECT 'Toi ten la banhmuy', 'My name is Elizabeth Myn';

SELECT TOP 5 *
FROM ecom_sale.dbo.customer;

-- WHERE: AND, OR
SELECT *
FROM ecom_sale.dbo.customer
WHERE customer_state='SP'AND customer_city='sao paulo'

SELECT *
FROM ecom_sale.dbo.customer
WHERE customer_state IN ('SP', 'MG')

-- BETWEEN ... AND

SELECT *
FROM ecom_sale.dbo.customer
WHERE customer_zip_code BETWEEN 5000 AND 10000
ORDER BY customer_zip_code, customer_id DESC

--- GROUP BY
-- Count customer for each state
SELECT customer_state,
	COUNT(DISTINCT customer_id) AS number_customer_state,
	COUNT(DISTINCT customer_unique_id) AS number_customer_state_unique_id
FROM ecom_sale.dbo.customer
GROUP BY customer_state

--- Annual amount statistics
SELECT TOP 5 *
FROM order_item;

SELECT YEAR(shipping_limit_date) AS year,
		SUM(amount) AS anual_amount,
		COUNT(order_item.order_id) as number_of_order
FROM order_item
GROUP BY YEAR(shipping_limit_date)
ORDER BY year ASC

-- Challenge
SELECT top 5 *
FROM order_history
-- 1
SELECT DISTINCT order_status
FROM order_history

-- 2
SELECT order_status,
	COUNT(order_id) as number_oder_id
FROM order_history
GROUP BY order_status

SELECT 
    order_status,
    COUNT(order_id) AS number_order_id,
    
    -- Bước 1: Tính tổng số lượng đơn hàng trên toàn bộ tập dữ liệu (Grand Total)
    SUM(COUNT(order_id)) OVER () AS total_orders, 
    -- Bước 2: Tính tỷ trọng (Lấy số lượng của từng nhóm chia cho tổng)
    CAST(COUNT(order_id) AS DECIMAL(10, 2)) * 100.0 / SUM(COUNT(order_id)) OVER () AS percentage_share
FROM 
    order_history
GROUP BY 
    order_status
ORDER BY 
    percentage_share DESC;

-- 3
