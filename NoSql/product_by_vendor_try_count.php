<?php

	require_once "../vendor/autoload.php";	
	$ProdVen = $_REQUEST['ProdVen'];
	$ProdVen = json_decode($ProdVen, true);
	$collection = (new MongoDB\Client)->POS->Product;
	//appropriate variables
	$vendorname = $ProdVen['vendor'];
	$position = $ProdVen['position'];
	
	$result = $collection->countDocuments(['vendors' => $vendorname]);
	
	
	echo json_encode($result);


?>