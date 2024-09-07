WITH SalesData AS (
    SELECT 
        p.product_id,
        u.units,
        p.price * u.units AS total_revenue
    FROM Prices p
    LEFT JOIN UnitsSold u 
    ON p.product_id = u.product_id 
    AND u.purchase_date BETWEEN p.start_date AND p.end_date
)
SELECT 
    product_id,
    ROUND(
        IFNULL(SUM(total_revenue) / SUM(units), 0), 2
    ) AS average_price
FROM SalesData
GROUP BY product_id;
