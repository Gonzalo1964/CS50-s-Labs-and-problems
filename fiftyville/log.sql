-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Look for the crime scene reports that day in that place:
SELECT description FROM crime_scene_reports WHERE year = 2020 AND month = 7 AND day = 28 AND street = "Chamberlin Street";

-- Description:
-- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
-- Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

-- Look for the interviews to the witnesses of the theft:
SELECT * FROM interviews WHERE year = 2020 AND month = 7 AND day = 28;
-- Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
-- If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, I was walking
-- by the ATM on Fifer Street and saw the thief there withdrawing some money.

-- As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- Look for plates in parking lot:
SELECT * FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28;
--260 | 2020 | 7 | 28 | 10 | 16 | exit | 5P2BI95
--261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X
--262 | 2020 | 7 | 28 | 10 | 18 | exit | 6P58WS2
--263 | 2020 | 7 | 28 | 10 | 19 | exit | 4328GD8
--264 | 2020 | 7 | 28 | 10 | 20 | exit | G412CB7
--265 | 2020 | 7 | 28 | 10 | 21 | exit | L93JTIZ
--266 | 2020 | 7 | 28 | 10 | 23 | exit | 322W7JE
--267 | 2020 | 7 | 28 | 10 | 23 | exit | 0NTHK55


-- Look for ATM´s
SELECT * FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street";
--246 | 28500762 | 2020 | 7 | 28 | Fifer Street | withdraw | 48
--264 | 28296815 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
--266 | 76054385 | 2020 | 7 | 28 | Fifer Street | withdraw | 60
--267 | 49610011 | 2020 | 7 | 28 | Fifer Street | withdraw | 50
--269 | 16153065 | 2020 | 7 | 28 | Fifer Street | withdraw | 80
--288 | 25506511 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
--313 | 81061156 | 2020 | 7 | 28 | Fifer Street | withdraw | 30
--336 | 26013199 | 2020 | 7 | 28 | Fifer Street | withdraw | 35

-- Relate account number with table of people:
SELECT * FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street"));
--id | name | phone_number | passport_number | license_plate
--395717 | Bobby | (826) 555-1652 | 9878712108 | 30G67EN
--396669 | Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ SUSPECT 1
--438727 | Victoria | (338) 555-6650 | 9586786673 | 8X428L0
--449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
--458378 | Roy | (122) 555-4581 | 4408372428 | QX4YZN3
--467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8 SUSPECT 2
--514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE SUSPECT 3
--686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X SUSPECT 4
--948985 | Robert | (098) 555-1164 | 8304650265 | I449449


-- Look for calls
SELECT * FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60;
--221 | (130) 555-0289 | (996) 555-8899 | 2020 | 7 | 28 | 51
--224 | (499) 555-9472 | (892) 555-8872 | 2020 | 7 | 28 | 36
--233 | (367) 555-5533 | (375) 555-8161 | 2020 | 7 | 28 | 45 SUSPECT 4
--251 | (499) 555-9472 | (717) 555-1342 | 2020 | 7 | 28 | 50
--254 | (286) 555-6063 | (676) 555-6554 | 2020 | 7 | 28 | 43
--255 | (770) 555-1861 | (725) 555-3243 | 2020 | 7 | 28 | 49 SUSPECT 3
--261 | (031) 555-6622 | (910) 555-3251 | 2020 | 7 | 28 | 38
--279 | (826) 555-1652 | (066) 555-9701 | 2020 | 7 | 28 | 55
--281 | (338) 555-6650 | (704) 555-2131 | 2020 | 7 | 28 | 54

-- Look for early flight leaving next day
SELECT * FROM flights WHERE year = 2020 AND month = 7 AND day = 29;
--18 | 8 | 6 | 2020 | 7 | 29 | 16 | 0
--23 | 8 | 11 | 2020 | 7 | 29 | 12 | 15
--36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20 EARLY FLIGHT FROM FIFTYVILLE
--43 | 8 | 1 | 2020 | 7 | 29 | 9 | 30
--53 | 8 | 9 | 2020 | 7 | 29 | 15 | 20

SELECT passport_number FROM passengers WHERE flight_id = 36;
--7214083635
--1695452385
--5773159633 SUSPECT 4 IS THE THIEF: ERNEST
--1540955065
--8294398571
--1988161715
--9878712108
--8496433585

-- Find out the city destination of the thief:
SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE id = 36);
--city
--London

-- Find out the accomplice
SELECT * FROM people WHERE phone_number = "(375) 555-8161";
--id | name | phone_number | passport_number | license_plate
--864400 | Berthold | (375) 555-8161 |  | 4V16VO0 BERTHOLD is the accomplice

