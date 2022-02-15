<?php 
	
	$product = $_POST['product'];
	$decodedProduct = json_decode($product, true);
	require_once "../vendor/autoload.php";	
	$collection = (new MongoDB\Client)->POS->Product;
	$decodedProduct['cost'] = (float)$decodedProduct['cost'];
	$decodedProduct['price'] = (float)$decodedProduct['price'];
	$decodedProduct['onhand'] = (int)$decodedProduct['onhand'];
	
	$insertOneResult = $collection->insertOne($decodedProduct);
	
	
	
	
?>
