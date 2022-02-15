<?php

	require_once "../vendor/autoload.php";	
	$collection = (new MongoDB\Client)->POS->Sales;
	$SaleByDate = $_REQUEST['SaleByDate'];
	$SaleByDate = json_decode($SaleByDate, true);
	$startD = $SaleByDate['start'];
	$finishD = $SaleByDate['finish'];
	
	$startD = new MongoDB\BSON\UTCDateTime(new \DateTimeImmutable($startD));
	$finishD = new MongoDB\BSON\UTCDateTime(new \DateTimeImmutable($finishD));
	
	$result = $collection->aggregate([['$match' => ['salesdate' => ['$gt' => $startD, '$lt' => $finishD]]], 
	['$group' => ['_id' => [ 'day' => [ '$dayOfYear' => '$salesdate'], 'year' => [ '$year' => '$salesdate' ] ]
	 ]],['$count' => 'total'] ]);
	 
	 
	 foreach ($result as $entry) 
	 {
	echo json_encode($entry);
	}

?>