<?php


	require_once "../vendor/autoload.php";	
	$collection = (new MongoDB\Client)->POS->Sales;
	$BestSell = $_REQUEST['BestSell'];
	$BestSell = json_decode($BestSell, true);
	
	
	//appropriate variables
	
	
	$page = isset($BestSell['page']) ? (int)$BestSell['page'] : 1;
	$limit = (int)$BestSell['limit'];
	$skip = ($page - 1) * $limit;
	
	
	#function getDOB($date)
	#{
	#	$utcdatetime = new MongoDB\BSON\UTCDateTime((string)$date);
	#	$datetime = $utcdatetime->toDateTime();
	#	$mydate = $datetime->format('Y-m-d');
	#	return $mydate;
	#}
	
	
	
	
	$result = $collection->aggregate([['$unwind' => '$items'],
	['$group' => ['_id' => '$items.ProdID' , 'pname' => ['$first' => '$items.ProdName' ]
	,'totalAmtSold' => ['$sum' => '$items.AmtSold']] ],['$sort' => ['totalAmtSold' => -1]], 
	['$limit' => $limit], ['$skip' => $skip] ]);
	

	
	foreach ($result as $entry) 
	{
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