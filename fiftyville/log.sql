-- To check out what the crime id is (295) by searching table crime_scene_reports
-- Also get the information that there were 3 witnesses. It took place at 10.15am.
SELECT * FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
AND street LIKE '%Humphrey Street%';

-- To check out the witnesses' trascripts. They look like following
-- Ruth (161): Sometime within ten minutes of the theft, I saw the thief get into
-- a car in the bakery parking lot and drive away. If you have security footage
-- from the bakery parking lot, you might want to look for cars that left the parking
-- lot in that time frame.
-- Eugene (162): I don't know the thief's name, but it was someone I recognized.
-- Earlier this morning, before I arrived at Emma's bakery, I was walking by the
-- ATM on Leggett Street and saw the thief there withdrawing some money.
-- Raymond (162): As the thief was leaving the bakery, they called someone who talked
-- to them for less than a minute. In the call, I heard the thief say that they were
-- planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked
-- the person on the other end of the phone to purchase the flight ticket.
SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

-- According to Eugene's scripts, check out atm_transactions and bank_accounts tables and got below account_number
-- person_id |
-- +-----------+
-- | 686048    |
-- | 514354    |
-- | 458378    |
-- | 395717    |
-- | 396669    |
-- | 467400    |
-- | 449774    |
-- | 438727    |
-- +-----------+
SELECT ba.person_id FROM bank_accounts ba, atm_transactions atm
WHERE ba.account_number = atm.account_number
AND year = 2021
AND month = 7
AND day = 28
AND atm_location LIKE '%Leggett Street%'
AND transaction_type LIKE '%withdraw%';

-- According to Raymond, the earliest flight: NYC. Flight id is 36.
SELECT * FROM flights WHERE year = 2021 AND month = 7 AND day = 29;

-- People who took the above flight:
SELECT id FROM people
WHERE passport_number IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id = 36);

-- Ruth: parking lot footage
SELECT license_plate FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND activity LIKE '%exit%'
AND hour = 10
AND minute < 25;

-- Phone call & ATM & footage: id(686048) name (Bruce)
SELECT id, name FROM people WHERE phone_number IN (
    SELECT caller FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60)
AND id IN(
    SELECT ba.person_id FROM bank_accounts ba, atm_transactions atm
    WHERE ba.account_number = atm.account_number
    AND year = 2021
    AND month = 7
    AND day = 28
    AND atm_location LIKE '%Leggett Street%'
    AND transaction_type LIKE '%withdraw%'
)
AND id IN(
    SELECT id FROM people
    WHERE passport_number IN (
        SELECT passport_number
        FROM passengers
        WHERE flight_id = 36)
)
AND id IN(
    SELECT p.id FROM people p, bakery_security_logs bsl
    WHERE p.license_plate = bsl.license_plate
    AND bsl.license_plate IN(
        SELECT license_plate FROM bakery_security_logs
        WHERE year = 2021
        AND month = 7
        AND day = 28
        AND activity LIKE '%exit%'
        AND hour = 10
        AND minute < 25
    )
);

-- The accomplice: Robin.
SELECT id, name FROM people
WHERE phone_number IN (
    SELECT receiver FROM phone_calls
    WHERE caller IN (
        SELECT phone_number FROM people
        WHERE id = 686048)
    AND year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60
);

