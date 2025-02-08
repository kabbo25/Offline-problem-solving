-- Create Sales table
CREATE TABLE Sales
(
    sale_id    INT,
    product_id INT,
    year       INT,
    quantity   INT,
    price      INT
);

-- Insert data into Sales table
INSERT INTO Sales (sale_id, product_id, year, quantity, price)
VALUES (1, 100, 2008, 10, 5000),
       (2, 100, 2009, 12, 5000),
       (7, 200, 2011, 15, 9000);

-- Create Product table
CREATE TABLE Product
(
    product_id   INT,
    product_name VARCHAR(100)
);

-- Insert data into Product table
INSERT INTO Product (product_id, product_name)
VALUES (100, 'Nokia'),
       (200, 'Apple'),
       (300, 'Samsung');


SELECT Product.product_name, Sales.year, Sales.price
FROM Sales
         NATURAL JOIN Product;