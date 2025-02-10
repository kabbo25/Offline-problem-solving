-- Create Visits table
CREATE TABLE Visits (
    visit_id INT,
    customer_id INT
);

-- Insert data into Visits table
INSERT INTO Visits (visit_id, customer_id) VALUES
(1, 23),
(2, 9),
(4, 30),
(5, 54),
(6, 96),
(7, 54),
(8, 54);

-- Create Transactions table
CREATE TABLE Transactions (
    transaction_id INT,
    visit_id INT,
    amount INT
);

-- Insert data into Transactions table
INSERT INTO Transactions (transaction_id, visit_id, amount) VALUES
(2, 5, 310),
(3, 5, 300),
(9, 5, 200),
(12, 1, 910),
(13, 2, 970);

SELECT * FROM Visits
LEFT JOIN leetcode_sql.transactions t on Visits.visit_id = t.visit_id;

SELECT v.customer_id, COUNT(v.customer_id) as count_no_trans
FROM Visits v
LEFT JOIN Transactions t ON v.visit_id = t.visit_id
WHERE t.transaction_id IS NULL
GROUP BY v.customer_id;

SELECT SUM(visit_id) FROM Visits;
SELECT MIN(Visits.customer_id) FROM Visits;
SELECT STDDEV(Visits.customer_id) FROM Visits;