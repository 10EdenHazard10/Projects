<?php 
	
	$product = $_POST['product'];
	$decodedProduct = json_decode($product, true);
	require_once "../vendor/autoload.php";	
	$collection = (new MongoDB\Client)->POS->Product;
	$decodedProduct['cost'] = (float)$decodedProduct['cost'];
	$decodedProduct['price'] = (float)$decodedProduct['price'];
	$decodedProduct['onhand'] = (int)$decodedProduct['onhand'];
	
	$insertOneResult = $collection->findOneAndReplace(['_id' => new MongoDB\BSON\ObjectID($decodedProduct['_id'])] , 
	['code' => $decodedProduct['code'],
	'name' => $decodedProduct['name'],
	'cost' => $decodedProduct['cost'],
	'price' => $decodedProduct['price'],
	'onhand' => $decodedProduct['onhand'],
	'vendors' => $decodedProduct['vendors']]);
	
	
	
	
	
?>