-- Q: 1571. Warehouse Manager

-- method 1: inner join
SELECT  Warehouse.name                                            AS warehouse_name
       ,SUM(units*Products.Width*Products.Length*Products.Height) AS volume
FROM Warehouse
INNER JOIN Products
ON Warehouse.product_id = Products.product_id
GROUP BY  Warehouse.name