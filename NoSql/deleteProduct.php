<?php 
	$id = $_REQUEST['_id'];
	require_once "../vendor/autoload.php";	
	$collection = (new MongoDB\Client)->POS->Product;
	$collection->deleteOne(['_id' => new MongoDB\BSON\ObjectID($id)]);
	
	
?>