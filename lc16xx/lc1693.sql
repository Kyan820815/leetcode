-- Q: 1693. Daily Leads and Partners

-- method 1: count distinct and group by
SELECT  date_id
       ,make_name
       ,COUNT(distinct(lead_id))    AS unique_leads
       ,COUNT(distinct(partner_id)) AS unique_partners
FROM DailySales
GROUP BY  date_id
         ,make_name