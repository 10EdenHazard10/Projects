<?php

	require_once "../vendor/autoload.php";	
	$ProdPriceRange = $_REQUEST['ProdPriceRange'];
	$ProdPriceRange = json_decode($ProdPriceRange, true);
	//appropriate variables
	$min = (float)$ProdPriceRange['min'];
	$max = (float)$ProdPriceRange['max'];
	$collection = (new MongoDB\Client)->POS->Product;
	//appropriate variables
	
	
	$result = $collection->countDocuments(['price' => [ '$gt' => $min, '$lt' => $max ] ]);
	
	
	echo json_encode($result);
	
?>