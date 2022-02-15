<?php

	
	require_once "../vendor/autoload.php";	
	$collection = (new MongoDB\Client)->POS->Product;
	$ProdPriceRange = $_REQUEST['ProdPriceRange'];
	$ProdPriceRange = json_decode($ProdPriceRange, true);
	//appropriate variables
	$min = (float)$ProdPriceRange['min'];
	$max = (float)$ProdPriceRange['max'];
	$page = isset($ProdPriceRange['page']) ? (int)$ProdPriceRange['page'] : 1;
	$limit = (int)$ProdPriceRange['limit'];
	$skip = ($page - 1) * $limit; //amount of documents to skip

	$result = $collection->find( ['price' => [ '$gt' => $min, '$lt' => $max ] ], ['limit' => $limit, 'skip' => $skip] );


	foreach ($result as $entry) 
	{
		$entry['cost'] = number_format($entry['cost'],2);
		$entry['price'] = number_format($entry['price'],2);
		$arr_out[] = $entry;
	}
	if (isset($arr_out))
	{
		echo json_encode($arr_out);

	}
	else
	{
		echo "";
	}

?>