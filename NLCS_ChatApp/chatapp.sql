create user 'root'@'%' identified by 'sang123';
grant all privileges on *.* to 'root'@'%' with grant option;
FLUSH PRIVILEGES;
-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Mar 08, 2024 at 08:38 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.0.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `chatapp`
--

-- --------------------------------------------------------

--
-- Table structure for table `messages`
--

CREATE TABLE `messages` (
  `id_message` int(50) NOT NULL,
  `sender` varchar(20) DEFAULT NULL,
  `receiver` varchar(20) DEFAULT NULL,
  `created_time` timestamp NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `message` text CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `messages`
--

INSERT INTO `messages` (`id_message`, `sender`, `receiver`, `created_time`, `message`) VALUES
(3, 'pmss0168', 'all', '2024-03-06 14:37:22', 'Hi guys! I\'m pmss0168!'),
(4, 'sang', 'pmss0168', '2024-03-06 14:40:06', 'Nice to meet you pmss0169'),
(5, 'sang', 'pmss0168', '2024-03-06 14:40:34', 'How you going'),
(6, 'pmss0168', 'sang', '2024-03-06 14:40:58', 'Tks I\'m great! How bout you'),
(7, 'sang', 'pmss0168', '2024-03-06 14:41:09', 'I\'m good!'),
(8, 'pmss0168', 'sang', '2024-03-06 17:21:46', 'Oh well! I have one idea to day'),
(9, 'sang', 'all', '2024-03-06 17:25:53', 'Hi pmss0168'),
(10, 'sang', 'all', '2024-03-06 17:30:52', 'Nice too meet you! ^^'),
(11, 'pmss0168', 'all', '2024-03-06 17:36:21', 'Can u go outside?'),
(12, 'sang', 'all', '2024-03-06 17:40:01', 'Yes, i can that good idea'),
(13, 'pmss0168', 'all', '2024-03-06 17:51:10', 'When you have free time? '),
(14, 'sang', 'all', '2024-03-06 18:00:49', 'I think at weekend'),
(15, 'pmss0168', 'all', '2024-03-06 18:02:41', 'Ok!'),
(16, 'sang', 'pmss0168', '2024-03-06 18:07:42', 'can I hear that'),
(17, 'sang', 'all', '2024-03-06 18:14:46', 'Now! i will prepare my clothes and some food'),
(18, 'sang', 'admin', '2024-03-06 18:15:55', 'Hi admin'),
(19, 'admin', 'sang', '2024-03-06 18:16:10', 'Hi sang! can i help you'),
(20, 'sang', 'all', '2024-03-07 05:15:41', 'What up!'),
(21, 'pmss0168', 'all', '2024-03-07 12:24:10', 'wasup'),
(22, 'admin', 'all', '2024-03-07 05:45:41', 'What is going on?'),
(23, 'pmss0168', 'all', '2024-03-07 11:51:10', 'Is anyone online?'),
(24, 'sang', 'all', '2024-03-07 11:51:20', 'I\'m here'),
(25, 'pmss0168', 'sang', '2024-03-07 12:23:26', '????????????????'),
(26, 'sang', 'pmss0168', '2024-03-07 14:19:50', 'Chúng ta có thể nói chuyện bằng Tiếng Việt được không?'),
(27, 'sang', 'pmss0168', '2024-03-07 14:19:59', 'tôi không hiểu gì cả'),
(28, 'pmss0168', 'all', '2024-03-07 14:31:24', 'Have a great day!'),
(29, 'pmss0168', 'sang', '2024-03-08 06:07:07', 'tất nhiên là được rồi!');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `username` varchar(20) NOT NULL,
  `password` varchar(200) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`username`, `password`) VALUES
('admin', 'c7ad44cbad762a5da0a452f9e854fdc1e0e7a52a38015f23f3eab1d80b931dd472634dfac71cd34ebc35d16ab7fb8a90c81f975113d6c7538dc69dd8de9077ec'),
('phamminhsang', '43f417b11ef5c881fa3621bf20a881fd506a31174572b32c4363de282b50a72b2ea315ff269ef90d31bd163237cf48956cce62dcc903a9e615ef4526fa5cd8cd'),
('pmss0168', 'a40b5c4ac324529b945e7ba98f46704675824487f5ec06679f0cc6a876806b2508856b15d3ed61471d03daf13364066b651d759cf68770dd22a3ad999d670d96'),
('pmss0169', '43f417b11ef5c881fa3621bf20a881fd506a31174572b32c4363de282b50a72b2ea315ff269ef90d31bd163237cf48956cce62dcc903a9e615ef4526fa5cd8cd'),
('sang', '43f417b11ef5c881fa3621bf20a881fd506a31174572b32c4363de282b50a72b2ea315ff269ef90d31bd163237cf48956cce62dcc903a9e615ef4526fa5cd8cd');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `messages`
--
ALTER TABLE `messages`
  ADD PRIMARY KEY (`id_message`),
  ADD KEY `fk_sender` (`sender`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`username`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `messages`
--
ALTER TABLE `messages`
  MODIFY `id_message` int(50) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=30;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `messages`
--
ALTER TABLE `messages`
  ADD CONSTRAINT `fk_sender` FOREIGN KEY (`sender`) REFERENCES `users` (`username`) ON DELETE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
