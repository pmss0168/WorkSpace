CREATE DATABASE  IF NOT EXISTS `chatapp` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `chatapp`;
-- MySQL dump 10.13  Distrib 8.0.36, for Win64 (x86_64)
--
-- Host: localhost    Database: chatapp
-- ------------------------------------------------------
-- Server version	8.0.36

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `friends`
--

DROP TABLE IF EXISTS `friends`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `friends` (
  `id_friend` int NOT NULL AUTO_INCREMENT,
  `friend_accept` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `friend_request` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `isAccept` tinyint NOT NULL DEFAULT '0',
  PRIMARY KEY (`id_friend`),
  KEY `fk_friend_idx` (`friend_accept`),
  KEY `fk_friend_of_idx` (`friend_request`),
  CONSTRAINT `fk_friend_name` FOREIGN KEY (`friend_accept`) REFERENCES `users` (`username`),
  CONSTRAINT `fk_friend_of` FOREIGN KEY (`friend_request`) REFERENCES `users` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `friends`
--

LOCK TABLES `friends` WRITE;
/*!40000 ALTER TABLE `friends` DISABLE KEYS */;
INSERT INTO `friends` VALUES (1,'pmss0169','admin',1),(2,'admin','sang',1),(8,'admin','pmss0168',1),(9,'sang','pmss0168',1),(10,'phamminhsang','sang',1),(11,'phamminhsang','admin',1),(12,'pmss0169','pmss0168',0);
/*!40000 ALTER TABLE `friends` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `messages`
--

DROP TABLE IF EXISTS `messages`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `messages` (
  `id_message` int NOT NULL AUTO_INCREMENT,
  `sender` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `receiver` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `created_time` datetime NOT NULL,
  `message` text CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NOT NULL,
  `notification` tinyint NOT NULL DEFAULT '1',
  PRIMARY KEY (`id_message`),
  KEY `fk_sender_idx` (`sender`),
  KEY `fk_receiver_idx` (`receiver`),
  CONSTRAINT `fk_receiver` FOREIGN KEY (`receiver`) REFERENCES `users` (`username`),
  CONSTRAINT `fk_sender` FOREIGN KEY (`sender`) REFERENCES `users` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=90 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `messages`
--

LOCK TABLES `messages` WRITE;
/*!40000 ALTER TABLE `messages` DISABLE KEYS */;
INSERT INTO `messages` VALUES (4,'sang','pmss0168','2024-03-06 21:40:06','Nice to meet you pmss0169',0),(5,'sang','pmss0168','2024-03-06 21:40:34','How you going',0),(6,'pmss0168','sang','2024-03-06 21:40:58','Tks I\'m great! How bout you',0),(7,'sang','pmss0168','2024-03-06 21:41:09','I\'m good!',0),(8,'pmss0168','sang','2024-03-07 00:21:46','Oh well! I have one idea to day',0),(16,'sang','pmss0168','2024-03-07 01:07:42','can I hear that',0),(18,'sang','admin','2024-03-07 01:15:55','Hi admin',0),(19,'admin','sang','2024-03-07 01:16:10','Hi sang! can i help you',0),(25,'pmss0168','sang','2024-03-07 19:23:26','???',0),(26,'sang','pmss0168','2024-03-07 21:19:50','Chúng ta có thể nói chuyện bằng Tiếng Việt được không?',0),(27,'sang','pmss0168','2024-03-07 21:19:59','tôi không hiểu gì cả',0),(29,'pmss0168','sang','2024-03-08 13:07:07','tất nhiên là được rồi!',0),(31,'sang','pmss0168','2024-03-08 19:15:01','bạn có biết bài Chúng ta của tương lai không?',0),(32,'pmss0168','sang','2024-03-08 19:15:29','Tôi biết, đó là bài nhạc mới ra của Sơn Tùng MTP, nghe giai điệu rất hay',0),(36,'sang','pmss0168','2024-03-17 18:54:20','Chào cậu',0),(37,'pmss0168','sang','2024-03-17 19:04:56','Buổi tối tốt lành',0),(38,'sang','pmss0168','2024-03-17 19:05:11','Ô cảm ơn cậu nhé',0),(39,'pmss0168','sang','2024-03-17 19:48:58','Tối nay cậu có đi chơi không',0),(40,'sang','pmss0168','2024-03-17 19:49:13','Không cậu ạ tối nay mình ở nhà',0),(41,'pmss0168','sang','2024-03-17 19:50:46','Cậu không thấy buồn à',0),(42,'sang','pmss0168','2024-03-17 19:51:01','Không cậu! tại tớ cũng quen rồi ấy^^',0),(43,'pmss0168','sang','2024-03-17 20:00:08','sao nghe cậu nói mà buồn thế',0),(46,'sang','pmss0168','2024-03-17 20:15:39','nói chứ tại không ai rủ tớ đi ấy! hahaha',0),(48,'sang','pmss0168','2024-03-23 15:51:59','Cuối tuần này cậu rảnh không',0),(49,'pmss0168','sang','2024-03-23 15:52:12','chắc là rảnh á cậu!',0),(50,'pmss0168','sang','2024-03-27 10:00:03','Đây là một tin nhắn',0),(51,'phamminhsang','tuitensang','2024-03-27 10:04:28','tui gửi 1 tin nhắn',0),(52,'sang','pmss0168','2024-03-27 10:05:24','đây là tin nhắn lúc 10:05',0),(53,'pmss0168','phamminhsang','2024-03-27 19:27:03','Buoi toi tot lanh',0),(54,'pmss0168','sang','2024-03-28 17:44:39','tin nhan moi',0),(55,'sang','pmss0168','2024-03-28 18:01:03','Oh well! I have one idea to day',0),(56,'sang','admin','2024-03-28 21:48:10','Can u pay your mousepad',0),(57,'sang','pmss0168','2024-03-29 00:41:53','test notify',0),(58,'pmss0168','sang','2024-03-29 00:48:03','oke',0),(59,'pmss0168','sang','2024-03-29 01:06:10','oke hen',0),(60,'sang','pmss0168','2024-03-29 01:10:21','qua la oke lun',0),(61,'pmss0168','admin','2024-03-29 01:38:07','chao admin',0),(62,'sang','admin','2024-03-29 01:38:15','chao admin',0),(63,'pmss0168','sang','2024-03-29 01:38:23','chao sang',0),(64,'sang','pmss0168','2024-03-29 01:38:37','xin chao pmss0168',0),(65,'pmss0168','sang','2024-03-29 01:43:31','test notify',0),(66,'sang','pmss0168','2024-03-29 01:43:39','test notify',0),(67,'sang','pmss0168','2024-03-29 01:43:49','test notify',0),(68,'admin','pmss0168','2024-03-29 01:45:52','chao pmss0168',0),(69,'sang','pmss0168','2024-03-29 01:46:03','oke tui da hieu roi',0),(70,'pmss0168','admin','2024-03-29 01:53:25','rất vui được gặp cậu',0),(71,'sang','admin','2024-03-29 01:53:49','tui mượn chat để test notify nhá',0),(72,'phamminhsang','admin','2024-03-29 01:55:27','chao admin',0),(73,'phamminhsang','admin','2024-03-29 01:56:34','chao nha',0),(74,'pmss0165','admin','2024-03-29 02:05:59','hello',0),(75,'admin','pmss0165','2024-03-29 02:12:23','chao pmss0165',0),(76,'pmss0165','admin','2024-03-29 02:14:39','wtf',0),(77,'admin','pmss0165','2024-03-29 02:14:54','how this like that',0),(78,'admin','pmss0168','2024-03-29 20:21:14','Hôm nay thật tuyệt vời cậu nhỉ',0),(79,'phamminhsang','admin','2024-03-29 20:44:54','day la mot tin nhan moi gui toi admin',0),(80,'admin','phamminhsang','2024-03-29 21:01:47','vang toi da nhin thay',0),(81,'admin','phamminhsang','2024-03-29 21:02:18','ban co can toi giup do gi khong',0),(82,'pmss0168','admin','2024-03-29 22:07:20','Hôm nay trời rất mát',0),(83,'admin','pmss0168','2024-03-29 22:07:59','thế chúng ta có nên làm một chuyến đi giả ngoại',0),(84,'admin','sang','2024-03-29 22:09:51','Cậu cứ thoải mái nhé',1),(85,'pmss0168','admin','2024-03-29 22:43:10','Tôi nghỉ là có',0),(86,'admin','pmss0168','2024-03-29 22:43:31','cậu muốn đi trong tuần này không',0),(87,'pmss0168','admin','2024-03-29 22:44:16','thế chúng ta chọn đi vào chủ nhật nhé!',0),(88,'pmss0169','admin','2024-03-30 12:47:28','Lời chào đầu tiên tới adminstator',1),(89,'pmss0168','admin','2024-03-30 12:47:49','Sao rồi cậu thấy như vậy có được không',0);
/*!40000 ALTER TABLE `messages` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `users` (
  `username` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `password` varchar(200) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `isOnline` tinyint NOT NULL DEFAULT '0',
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES ('admin','c7ad44cbad762a5da0a452f9e854fdc1e0e7a52a38015f23f3eab1d80b931dd472634dfac71cd34ebc35d16ab7fb8a90c81f975113d6c7538dc69dd8de9077ec',0),('phamminhsang','43f417b11ef5c881fa3621bf20a881fd506a31174572b32c4363de282b50a72b2ea315ff269ef90d31bd163237cf48956cce62dcc903a9e615ef4526fa5cd8cd',0),('phamminhsang11','43f417b11ef5c881fa3621bf20a881fd506a31174572b32c4363de282b50a72b2ea315ff269ef90d31bd163237cf48956cce62dcc903a9e615ef4526fa5cd8cd',0),('pmss0165','43f417b11ef5c881fa3621bf20a881fd506a31174572b32c4363de282b50a72b2ea315ff269ef90d31bd163237cf48956cce62dcc903a9e615ef4526fa5cd8cd',0),('pmss0166','43f417b11ef5c881fa3621bf20a881fd506a31174572b32c4363de282b50a72b2ea315ff269ef90d31bd163237cf48956cce62dcc903a9e615ef4526fa5cd8cd',0),('pmss0167','43f417b11ef5c881fa3621bf20a881fd506a31174572b32c4363de282b50a72b2ea315ff269ef90d31bd163237cf48956cce62dcc903a9e615ef4526fa5cd8cd',0),('pmss0168','a40b5c4ac324529b945e7ba98f46704675824487f5ec06679f0cc6a876806b2508856b15d3ed61471d03daf13364066b651d759cf68770dd22a3ad999d670d96',1),('pmss0169','43f417b11ef5c881fa3621bf20a881fd506a31174572b32c4363de282b50a72b2ea315ff269ef90d31bd163237cf48956cce62dcc903a9e615ef4526fa5cd8cd',0),('sang','43f417b11ef5c881fa3621bf20a881fd506a31174572b32c4363de282b50a72b2ea315ff269ef90d31bd163237cf48956cce62dcc903a9e615ef4526fa5cd8cd',0),('tuitensang','43f417b11ef5c881fa3621bf20a881fd506a31174572b32c4363de282b50a72b2ea315ff269ef90d31bd163237cf48956cce62dcc903a9e615ef4526fa5cd8cd',0);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-03-31 20:53:25
