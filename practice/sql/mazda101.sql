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

--- Annual amount statistics -- Thong ke so tien theo nam giao hang
SELECT TOP 5 *
FROM order_item;

SELECT YEAR(shipping_limit_date) AS [year],
		SUM(amount) AS anual_amount,
		COUNT(order_item.order_id) as number_of_order
FROM order_item
GROUP BY YEAR(shipping_limit_date)
ORDER BY year ASC

-- Challenge
SELECT top 5 *
FROM order_history
-- 1 Trạng thái của các đơn hàng đang được giao nhận
SELECT DISTINCT order_status
FROM order_history

-- 2 Tỷ trọng số lượng đơn hàng theo trạng thái là bao nhiêu, cho biết tỷ lệ đơn hàng giao thành công?
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
    CAST(
    ROUND(
        CAST(
            COUNT(order_id) AS DECIMAL(18, 5)
        )
        * 100.0 / SUM(COUNT(order_id)) OVER (),
        3
    ) -- End ROUND

    AS DECIMAL(18, 3)
) AS percentage_share
FROM order_history
GROUP BY order_status
ORDER BY percentage_share DESC;

-- 3 Có sự khác biệt quá lớn về tỷ lệ giao hàng thành công giữa các customer_state hay không?
-- Tỷ lệ giao hàng thành công cho mỗi state
SELECT c.customer_state,COUNT(DISTINCT order_id) as number_success_order
FROM order_history as o, customer as c
WHERE c.customer_id = o.customer_id AND order_status = 'delivered'
GROUP BY customer_state

-- Tổng số lượng đơn hàng cho mỗi state
SELECT c.customer_state,COUNT(DISTINCT order_id) as number_order
FROM order_history as o, customer as c
WHERE c.customer_id = o.customer_id
GROUP BY customer_state

-- show cột ở 2 bảng

SELECT TOP 5 *
FROM order_history as o
JOIN customer as c
ON c.customer_id = o.customer_id

---
SELECT o.*, -- lấy tất cả các cột của order_history
        c.customer_state,
        c.customer_city
FROM order_history as o
JOIN customer as c
    ON c.customer_id = o.customer_id

--

SELECT customer_state,COUNT(DISTINCT order_id) as number_success_order
FROM order_history as o
JOIN customer as c
ON c.customer_id = o.customer_id
GROUP BY customer_state;

-- b1 Tạo bản tạm để lưu kết quả lại
WITH table_joined AS (
    SELECT o.* -- lấy tất cả các cột của order_history
           , c.customer_city
           , c.customer_state
    FROM order_history as o
    JOIN customer as c
        ON c.customer_id = o.customer_id
)
, table_delivered AS(
    SELECT customer_state
           , COUNT(order_id) AS number_delivered
    FROM table_joined
    WHERE order_status = 'delivered'
    GROUP BY customer_state
)
-- b3 Đếm số đơn hàng tổng của từng state
, table_total AS (
    SELECT customer_state
           , COUNT(order_id) AS total_order
    FROM table_joined
    GROUP BY customer_state
)
-- b4 join 2 kết quả lại với nhau: table_delivered và table_total, ở đây chúng ta dùng FULL JOIN để đề phòng trường hợp kết quả giao hàng thành công nhưng không có total
SELECT table_total.*
       , table_delivered.number_delivered
       , CAST(
              ROUND(CAST(number_delivered AS FLOAT) * 100 / CAST(total_order AS FLOAT), 3)
              AS DECIMAL(18, 3)) AS deliver_success_rate
FROM table_total
FULL JOIN table_delivered
    ON table_total.customer_state = table_delivered.customer_state

-- BAI 4 Quan sát theo thời gian, có bất thường về tỷ lệ giao hàng thành công hay không?
--B1 Lấy thời gian ra, xử lý thông tin về năm và tháng cho history
WITH table_month as (
    SELECT order_id, order_status, purchase_time
        , CONVERT(varchar(7), purchase_time) AS order_purchase_time
    FROM order_history
)
-- b2 group by theo tháng và đếm số đơn hàng total
, table_total_order AS (
    SELECT order_purchase_time
           , COUNT(order_id) as total_order
    FROM table_month
    GROUP BY order_purchase_time
)
-- B3 Đếm số đơn hàng được giao thành công
, table_success_order AS (
    SELECT order_purchase_time
           , COUNT(order_id) as total_success_order
    FROM table_month
    WHERE order_status = 'delivered'
    GROUP BY order_purchase_time
)
SELECT table_total_order.order_purchase_time
        , CAST(table_success_order.total_success_order AS FLOAT) AS total_success_order
       , table_total_order.total_order
       , CAST((CAST(total_success_order AS FLOAT) * 100 / CAST(total_order AS FLOAT)) AS DECIMAL(18,2)) AS delivery_success_rate
FROM table_total_order
FULL JOIN table_success_order
    ON table_total_order.order_purchase_time = table_success_order.order_purchase_time
ORDER BY order_purchase_time ASC
