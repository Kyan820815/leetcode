-- Q: 1683. Invalid Tweets

-- method 1: char length
SELECT  tweet_id
FROM Tweets
WHERE char_length(content) > 15