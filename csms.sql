-- phpMyAdmin SQL Dump
-- version 4.7.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 28, 2022 at 05:53 PM
-- Server version: 10.1.25-MariaDB
-- PHP Version: 7.1.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `csms`
--

-- --------------------------------------------------------

--
-- Table structure for table `clothmenu`
--

CREATE TABLE `clothmenu` (
  `ClothID` int(11) NOT NULL,
  `ClothName` varchar(60) COLLATE utf8mb4_bin NOT NULL,
  `Price` double NOT NULL,
  `fabric` varchar(250) COLLATE utf8mb4_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `clothmenu`
--

INSERT INTO `clothmenu` (`ClothID`, `ClothName`, `Price`, `fabric`) VALUES
(18, 'Panjabi', 50, 'Cotton'),
(20, 'Hijab', 50, 'Chiffon'),
(21, 'Pant', 30, 'Cotton'),
(22, 'Kamij', 40, 'Silk'),
(24, 'shirt', 90, 'Silk'),
(25, 'Borka', 60, 'Silk'),
(26, 'long shirt', 30, 'Velvet'),
(29, 'kurta', 60, 'Silk'),
(30, 'Dupatta', 70, 'Chiffon'),
(32, 'Short Shirt', 50, 'Chiffon'),
(33, 'shirt', 60, 'Cotton'),
(34, 'shirt', 30, 'Silk'),
(35, 'Pant', 40, 'Cotton');

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `CustomerID` int(11) NOT NULL,
  `CustomerName` varchar(60) COLLATE utf8mb4_bin NOT NULL,
  `PhoneNumber` varchar(50) COLLATE utf8mb4_bin DEFAULT NULL,
  `password` varchar(250) COLLATE utf8mb4_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`CustomerID`, `CustomerName`, `PhoneNumber`, `password`) VALUES
(1, 'israt', '0123456780', 'abcd12'),
(2, 'jahan', '1234567890', 'bcde12'),
(3, 'bhuiyan', '123456', 'asd45'),
(4, 'sumaiya', '123456', 'epm45'),
(5, 'suraiya', '1234', 'acp56'),
(6, 'shefali', '0123456789', '12345'),
(7, 'mozammel', '023456', 'ab12'),
(8, 'dua', '12345', '76645'),
(9, 'aqsa', '045678', '34565'),
(10, 'abiha', '45678', '32455'),
(11, 'mahrosh', '123456', '12300'),
(12, 'surat', '12345', '12'),
(40, 'intisarat', '0123456789', '67890'),
(41, 'afreen', '0111122220', '123456'),
(42, 'israt', '0987654321', '333333'),
(43, 'rubaiya', '9999999999', '111111'),
(44, 'israt', '9999999999', '9999'),
(45, 'israt', '9999999999', '6666'),
(46, 'israt', '4444444444', '4444'),
(47, 'eva', '9999999999', '5555'),
(48, 'Rita', '0987654321', '1111'),
(49, 'israt', '3333333333', '3333');

-- --------------------------------------------------------

--
-- Table structure for table `orderlist`
--

CREATE TABLE `orderlist` (
  `OrderID` int(11) NOT NULL,
  `Quantity` int(60) NOT NULL,
  `CustomerID` int(11) DEFAULT NULL,
  `ClothID` int(11) DEFAULT NULL,
  `Price` double NOT NULL,
  `Name` varchar(60) COLLATE utf8mb4_bin NOT NULL,
  `Status` varchar(250) COLLATE utf8mb4_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `orderlist`
--

INSERT INTO `orderlist` (`OrderID`, `Quantity`, `CustomerID`, `ClothID`, `Price`, `Name`, `Status`) VALUES
(1, 9, 42, 20, 135, 'Hijab', 'Added to Cart'),
(2, 5, 42, 21, 200, 'top', 'Added to Cart'),
(3, 5, 43, 24, 450, 'shirt', 'Added to Cart'),
(5, 0, 45, 29, 0, 'kurta', 'Added to Cart'),
(6, 6, 47, 30, 420, 'Dupatta', 'Added to Cart'),
(7, 7, 48, 32, 350, 'Short Shirt', 'Added to Cart'),
(8, 5, 49, 34, 150, 'shirt', 'Added to Cart');

-- --------------------------------------------------------

--
-- Table structure for table `receipt`
--

CREATE TABLE `receipt` (
  `ReceiptID` int(11) NOT NULL,
  `CustomerID` int(11) DEFAULT NULL,
  `TotalPrice` double NOT NULL,
  `CardNumber` int(11) NOT NULL,
  `paymentMethod` varchar(11) COLLATE utf8mb4_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `receipt`
--

INSERT INTO `receipt` (`ReceiptID`, `CustomerID`, `TotalPrice`, `CardNumber`, `paymentMethod`) VALUES
(59, 6, 146, 7890, 'Card'),
(61, 6, 115, 0, 'Cash'),
(65, 40, 400, 0, 'Cash'),
(67, 41, 116, 7892, 'Card'),
(68, 41, 116, 0, 'Cash'),
(69, 42, 135, 0, ''),
(70, 42, 135, 4433, 'Card'),
(71, 42, 335, 0, ''),
(72, 43, 785, 0, ''),
(73, 43, 785, 5555, 'Card'),
(74, 48, 1555, 0, ''),
(75, 48, 1555, 9654, 'Card'),
(76, 49, 1705, 0, 'Cash'),
(77, 49, 1705, 4444, 'Card');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `clothmenu`
--
ALTER TABLE `clothmenu`
  ADD PRIMARY KEY (`ClothID`);

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`CustomerID`);

--
-- Indexes for table `orderlist`
--
ALTER TABLE `orderlist`
  ADD PRIMARY KEY (`OrderID`),
  ADD KEY `OrderList_Customer_FK` (`CustomerID`),
  ADD KEY `OrderList_ClothMenu_FK` (`ClothID`);

--
-- Indexes for table `receipt`
--
ALTER TABLE `receipt`
  ADD PRIMARY KEY (`ReceiptID`),
  ADD KEY `Receipt_Customer_FK` (`CustomerID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `clothmenu`
--
ALTER TABLE `clothmenu`
  MODIFY `ClothID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=36;
--
-- AUTO_INCREMENT for table `customer`
--
ALTER TABLE `customer`
  MODIFY `CustomerID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=50;
--
-- AUTO_INCREMENT for table `orderlist`
--
ALTER TABLE `orderlist`
  MODIFY `OrderID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
--
-- AUTO_INCREMENT for table `receipt`
--
ALTER TABLE `receipt`
  MODIFY `ReceiptID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=78;
--
-- Constraints for dumped tables
--

--
-- Constraints for table `orderlist`
--
ALTER TABLE `orderlist`
  ADD CONSTRAINT `OrderList_ClothMenu_FK` FOREIGN KEY (`ClothID`) REFERENCES `clothmenu` (`ClothID`),
  ADD CONSTRAINT `OrderList_Customer_FK` FOREIGN KEY (`CustomerID`) REFERENCES `customer` (`CustomerID`);

--
-- Constraints for table `receipt`
--
ALTER TABLE `receipt`
  ADD CONSTRAINT `Receipt_Customer_FK` FOREIGN KEY (`CustomerID`) REFERENCES `customer` (`CustomerID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
