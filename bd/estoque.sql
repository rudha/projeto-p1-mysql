-- MySQL dump 10.14  Distrib 5.5.37-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: estoque
-- ------------------------------------------------------
-- Server version	5.5.37-MariaDB-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Contas_de_usuario`
--

DROP TABLE IF EXISTS `Contas_de_usuario`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Contas_de_usuario` (
  `Id` int(11) DEFAULT NULL,
  `Login` char(20) DEFAULT NULL,
  `Senha` char(20) DEFAULT NULL,
  `Nome_completo` char(100) DEFAULT NULL,
  `Nivel_de_permissoes` tinyint(4) DEFAULT NULL,
  `Estado_do_item` tinyint(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Contas_de_usuario`
--

LOCK TABLES `Contas_de_usuario` WRITE;
/*!40000 ALTER TABLE `Contas_de_usuario` DISABLE KEYS */;
/*!40000 ALTER TABLE `Contas_de_usuario` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Lotes`
--

DROP TABLE IF EXISTS `Lotes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Lotes` (
  `Id` int(11) DEFAULT NULL,
  `Id_do_produto` int(11) DEFAULT NULL,
  `Nome_do_produto` char(100) DEFAULT NULL,
  `Fabricante` char(100) DEFAULT NULL,
  `Tempo_de_garantia` float DEFAULT NULL,
  `Referencia` char(20) DEFAULT NULL,
  `Data_de_entrada` char(10) DEFAULT NULL,
  `Quantidade` int(11) DEFAULT NULL,
  `Valor_de_compra` int(11) DEFAULT NULL,
  `Estado_do_item` tinyint(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Lotes`
--

LOCK TABLES `Lotes` WRITE;
/*!40000 ALTER TABLE `Lotes` DISABLE KEYS */;
/*!40000 ALTER TABLE `Lotes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Produtos`
--

DROP TABLE IF EXISTS `Produtos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Produtos` (
  `Id` int(11) DEFAULT NULL,
  `Nome` char(100) DEFAULT NULL,
  `Fabricante` char(100) DEFAULT NULL,
  `Tempo_de_garantia` float DEFAULT NULL,
  `Referencia` char(20) DEFAULT NULL,
  `Estado_do_item` tinyint(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Produtos`
--

LOCK TABLES `Produtos` WRITE;
/*!40000 ALTER TABLE `Produtos` DISABLE KEYS */;
/*!40000 ALTER TABLE `Produtos` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2014-06-12 21:26:50
