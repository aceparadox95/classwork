-- 1 Find the film title and language name of all films in which ADAM GRANT acted
-- Order the results by title, descending (use ORDER BY title DESC at the end of the query)

SELECT fm.title, lg.name, a.first_name, a.last_name
FROM film fm
INNER JOIN language lg ON lg.language_id = fm.language_id
INNER JOIN film_actor fa ON fa.film_id = fm.film_id
INNER JOIN actor a ON a.actor_id = fa.actor_id
WHERE a.first_name =  'ADAM'
AND a.last_name =  'GRANT'
ORDER BY fm.title DESC;

-- We want to find out how many of each category of film ED CHASE has started in so return a table with category.name and the count
-- of the number of films that ED was in which were in that category order by the category name ascending (Your query should return every category even if ED has been in no films in that category).
-- Used help from this piazza discussion to eventually figure this out: https://piazza.com/class/iex70tm68ym22g?cid=64

SELECT cat.name AS category, COUNT( dt.film_id ) AS film
FROM category cat
LEFT JOIN (
SELECT fc.category_id, fc.film_id, a.actor_id
FROM film_category fc
INNER JOIN film fm ON fc.film_id = fm.film_id
INNER JOIN film_actor fa ON fa.film_id = fm.film_id
INNER JOIN actor a ON a.actor_id = fa.actor_id
WHERE a.first_name =  'ED'
AND a.last_name =  'CHASE'
) AS dt ON cat.category_id = dt.category_id
GROUP BY cat.name
ORDER BY cat.name ASC;


-- Find the first name, last name and total combined film length of Sci-Fi films for every actor
-- That is the result should list the names of all of the actors(even if an actor has not been in any Sci-Fi films)and the total length of Sci-Fi films they have been in.

SELECT a.first_name, a.last_name, SUM( dt.length ) 
FROM actor a
LEFT JOIN (
SELECT a.actor_id, fm.length
FROM film fm
INNER JOIN film_actor fa ON fa.film_id = fm.film_id
INNER JOIN actor a ON a.actor_id = fa.actor_id
INNER JOIN film_category fc ON fc.film_id = fm.film_id
INNER JOIN category cat ON cat.category_id = fc.category_id
WHERE cat.name =  'Sci-Fi'
) AS dt ON dt.actor_id = a.actor_id
GROUP BY a.actor_id;



-- #4 Find the first name and last name of all actors who have never been in a Sci-Fi film

SELECT a.first_name, a.last_name
FROM actor a
WHERE a.actor_id NOT 
IN (
SELECT a.actor_id
FROM film fm
INNER JOIN film_actor fa ON fa.film_id = fm.film_id
INNER JOIN actor a ON a.actor_id = fa.actor_id
INNER JOIN film_category fc ON fc.film_id = fm.film_id
INNER JOIN category cat ON cat.category_id = fc.category_id
WHERE cat.name =  'Sci-Fi'
);

-- #5 Find the film title of all films which feature both KIRSTEN PALTROW and WARREN NOLTE
-- #Order the results by title, descending (use ORDER BY title DESC at the end of the query)
-- #Warning, this is a tricky one and while the syntax is all things you know, you have to think oustide
-- #the box a bit to figure out how to get a table that shows pairs of actors in movies

SELECT fm.title
FROM film fm
WHERE fm.film_id IN
(SELECT fm.film_id
FROM actor a
INNER JOIN film_actor fa ON fa.actor_id = a.actor_id
INNER JOIN film fm ON fm.film_id = fa.film_id
WHERE a.first_name = 'WARREN' AND a.last_name =  'NOLTE')
AND fm.film_id IN
(SELECT fm.film_id
FROM actor a
INNER JOIN film_actor fa ON fa.actor_id = a.actor_id
INNER JOIN film fm ON fm.film_id = fa.film_id
WHERE a.first_name = 'KIRSTEN' AND a.last_name =  'PALTROW')
ORDER BY fm.title DESC;


