<?php

	require_once "../vendor/autoload.php";	
	$SaleByDate = $_REQUEST['SaleByDate'];
	$SaleByDate = json_decode($SaleByDate, true);
	$collection = (new MongoDB\Client)->POS->Sales;
	$startD = $SaleByDate['start'];
	$finishD = $SaleByDate['finish'];
	//appropriate variables
	$page = isset($SaleByDate['page']) ? (int)$SaleByDate['page'] : 1;
	$limit = (int)$SaleByDate['limit'];
	$skip = ($page - 1) * $limit;


	
	function getDOB($date)
	{
		$utcdatetime = new MongoDB\BSON\UTCDateTime((string)$date);
		$datetime = $utcdatetime->toDateTime();
		$mydate = $datetime->format('Y-m-d');
		return $mydate;
	}
	
	$startD = new MongoDB\BSON\UTCDateTime(new \DateTimeImmutable($startD));
	$finishD = new MongoDB\BSON\UTCDateTime(new \DateTimeImmutable($finishD));
	
	
	$result = $collection->aggregate([
									[
										'$match' => ['salesdate' => ['$gt' => $startD, '$lt' => $finishD]]
									],
									[
	
										'$group' => [
													'_id' => [ 'day' => ['$dayOfYear' => '$salesdate'], 'year' => [ '$year' => '$salesdate' ] ], 
													'date' => ['$first' => '$salesdate'],
													'counter' => ['$sum' => 1],
													'amt' => ['$sum' => '$salestotal'] ,
													'avgAmt' => ['$avg' => '$salestotal']
													
													]	
									],
									[
										'$sort' => ['_id' => 1]
									],
									[
										'$limit' => $limit
									], 
									[
										'$skip' => $skip
									]
								]);
	
	
	
		
	foreach ($result as $entry) 
	{
	$entry['date'] = getDOB($entry['date']);
	$entry['amt'] = number_format($entry['amt'],2);
	$entry['avgAmt'] = number_format($entry['avgAmt'],2);
	#$entry['count'] = number_format($entry['count'],2);
	
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