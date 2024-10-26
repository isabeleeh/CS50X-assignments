-- Keep a log of any SQL queries you execute as you solve the mystery.
// took place on July 28, 2021 on Humphrey Street....CS50 duck stolen
select * from crime_scene_reports where description like '%duck%';

// 3 witness check
select * from interviews where transcript like '%bakery%';

// wit2: atm transaction info to locate 'withdraw info on Jul 28th'
select * from atm_transactions
where transaction_type = 'withdraw'
and atm_location like '%Leggett%' and year = '2021'
and month = '7' and day = '28';

// map above withdraw account_numbers to people info/names
select p.*, ba.account_number,at.id from atm_transactions at
inner join bank_accounts ba on at.account_number = ba.account_number
inner join people p on p.id = ba.person_id
where transaction_type = 'withdraw'
and atm_location like '%Leggett%'
and year = '2021' and month = '7' and day = '28'
order by at.id;

// wit1: flight info to locate ESCAPED to
select * from flights
where year = '2021' and month = '7' and day = '29'
order by hour, minute limit 5;
// got destination city
select * from airports where id = '4';

// atm info + above flight info....reduced to 4 results/people
select p.*, ba.account_number,at.id from atm_transactions at
inner join bank_accounts ba on at.account_number = ba.account_number
inner join people p on p.id = ba.person_id
inner join passengers pa on pa.passport_number = p.passport_number
where transaction_type = 'withdraw'
and atm_location like '%Leggett%'
and year = '2021' and month = '7' and day = '28'
and pa.flight_id = '36'
order by at.id;

// wit1: car parking info to identify a few people
select p.*,bsl.hour, bsl.minute from bakery_security_logs bsl
inner join people p on p.license_plate = bsl.license_plate
where bsl.year = '2021' and bsl.month = '7' and bsl.day = '28'
and bsl.hour = '10'
and bsl.minute > '15'
and bsl.minute < '25';

// atm + flight + car park .....to reduce to 2 people
select p.*, ba.account_number,at.id from atm_transactions at
inner join bank_accounts ba on at.account_number = ba.account_number
inner join people p on p.id = ba.person_id
inner join passengers pa on pa.passport_number = p.passport_number
inner join bakery_security_logs bsl on bsl.license_plate = p.license_plate
where transaction_type = 'withdraw'
and atm_location like '%Leggett%'
and at.year = '2021' and at.month = '7' and at.day = '28'
and pa.flight_id = '36'
and bsl.year = '2021' and bsl.month = '7' and bsl.day = '28'
and bsl.hour = '10'
and bsl.minute > '15'
and bsl.minute < '25'
order by at.id;

// plus phone_call records, only Bruce hits
select p.*, pc.* from people p
inner join phone_calls pc on p.phone_number = pc.caller
where (p.name = 'Luca' or p.name = 'Bruce')
and day = '28';

// plus less than a minute talk, locate the receiver - Robin
select p.*, pc.*, p2.name as receiver from phone_calls pc
inner join people p on p.phone_number = pc.caller
inner join people p2 on p2.phone_number = pc.receiver
where (p.name = 'Luca' or p.name = 'Bruce')
and day = '28'
and pc.duration < '60';

select * from flights
where year = '2021' and month = '7' and day = '29'
order by hour, minute limit 5;
// got destination city
select * from airports where id = '4';

SELECT f.id, origin_airport_id, full_name, destination_airport_id, full_name FROM flights f, airports a LIMIT 10;
SELECT f.id, origin_airport_id, city, destination_airport_id, city FROM flights f, airports a LIMIT 10;

SELECT origin_airport_id, airports.full_name, destination_airport_id, a2.full_name
FROM flights
INNER JOIN airports ON flights.origin_airport_id = airports.id
INNER JOIN airports a2 ON flights.destination_airport_id = a2.id;

SELECT origin_airport_id, airports.full_name, destination_airport_id, a2.full_name FROM flights, airports, airports a2 WHERE flights.origin_airport_id = airports.id AND flights.destination_airport_id = a2.id;

sqlite> SELECT * FROM airports;
+----+--------------+-----------------------------------------+---------------+
| id | abbreviation |                full_name                |     city      |
+----+--------------+-----------------------------------------+---------------+
| 1  | ORD          | O'Hare International Airport            | Chicago       |
| 2  | PEK          | Beijing Capital International Airport   | Beijing       |
| 3  | LAX          | Los Angeles International Airport       | Los Angeles   |
| 4  | LGA          | LaGuardia Airport                       | New York City |
| 5  | DFS          | Dallas/Fort Worth International Airport | Dallas        |
| 6  | BOS          | Logan International Airport             | Boston        |
| 7  | DXB          | Dubai International Airport             | Dubai         |
| 8  | CSF          | Fiftyville Regional Airport             | Fiftyville    |
| 9  | HND          | Tokyo International Airport             | Tokyo         |
| 10 | CDG          | Charles de Gaulle Airport               | Paris         |
| 11 | SFO          | San Francisco International Airport     | San Francisco |
| 12 | DEL          | Indira Gandhi International Airport     | Delhi         |
+----+--------------+-----------------------------------------+---------------+

