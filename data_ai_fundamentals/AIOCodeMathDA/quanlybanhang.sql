#select now() from dual;
-- SELECT * FROM quanlybanhang.salespersons;
-- SELECT * FROM quanlybanhang.orders;
-- SELECT * FROM quanlybanhang.customers;

# • Câu 4: Chèn dữ liệu vào bảng Salespersons.
INSERT INTO quanlybanhang.salespersons (SalespersonID, FullName, Email, PhoneNumber) VALUES
(1, 'Le A', 'ale@x.com', '0123234098'),
(2, 'Nguyen B', 'bnguyen@x.com', '0483294939'),
(3, 'Tran C', 'ctran@x.com', '0938293930');


# • Câu 5: Chèn dữ liệu vào bảng Customers.
INSERT INTO quanlybanhang.customers(CustomerID, FullName, Email, PhoneNumber) VALUES
(1, 'Trieu D', 'dtrieu@x.com', '0125634098'),
(2, 'Ly E', 'ely@x.com', '0163234098'),
(3, 'Le G', 'gle@x.com', '0973234098');


--  • Câu 6: Chèn dữ liệu vào bảng Orders.
INSERT INTO quanlybanhang.orders (OrderID, CustomerID, SalespersonID, OrderDate, TotalAmount) VALUES
(1, 1, 1, '2024-12-24', 5000000),
(2, 2, 2, '2024-12-25', 3000000),
(3, 3, 3, '2024-12-26', 7000000);


# • Câu 7: Liệt kê tất cả các đơn hàng của nhân viên có SalespersonID = 1.
SELECT * FROM quanlybanhang.orders o  WHERE SalespersonID = 1;

# • Câu 8: Tìm khách hàng có số lượng đơn hàng nhiều nhất.
SELECT o.CustomerID, c.FullName, COUNT(1) AS TotalOrders
FROM
    quanlybanhang.orders o inner join quanlybanhang.customers c
    where 1 = 1 AND o.CustomerID = c.CustomerID
GROUP BY CustomerID
ORDER BY TotalOrders DESC
LIMIT 1;

# • Câu 9: Tính tổng doanh số của từng nhân viên.
SELECT CustomerID, COUNT(*) AS TotalOrders
FROM quanlybanhang.orders
GROUP BY CustomerID
ORDER BY TotalOrders DESC
LIMIT 1;

  # • Câu 10: Tìm nhân viên có doanh số cao nhất.
SELECT SalespersonID, SUM(TotalAmount) AS TotalSales
FROM quanlybanhang.orders
GROUP BY SalespersonID
ORDER BY TotalSales DESC
LIMIT 1;

# • Câu 11: Cập nhật tổng giá trị đơn hàng có OrderID = 2 thành 4.500.000
UPDATE quanlybanhang.orders o 
SET o.TotalAmount = 4500000
WHERE o.OrderID = 2;

# • Câu 12: Cập nhật số điện thoại của khách hàng có CustomerID = 3
UPDATE quanlybanhang.customers c 
SET PhoneNumber = '0963234098'
WHERE CustomerID = 3

# • Câu 13: Xóa tất cả các đơn hàng của khách hàng có CustomerID = 2
DELETE FROM quanlybanhang.orders  WHERE CustomerID = 2