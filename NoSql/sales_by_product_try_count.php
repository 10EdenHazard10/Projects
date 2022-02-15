<?php

	require_once "../vendor/autoload.php";	
	$SaleByProd = $_REQUEST['SaleByProd'];
	$SaleByProd = json_decode($SaleByProd, true);
	$collection = (new MongoDB\Client)->POS->Sales;
	$pcode = $SaleByProd['pcode'];
	
	
	$result = $collection->aggregate([['$unwind' => '$items'],
	['$match' => ['items.ProdID' => $pcode]], ['$group' => ['_id' => 
	[ 'day' => [ '$dayOfYear' => '$salesdate'], 'year' => 
	[ '$year' => '$salesdate' ] ], 
	]],['$count' => 'total'] ]);
	
	
	foreach ($result as $entry) 
	{
	echo json_encode($entry);
	}
	
	
	
?>