<?php	
	require_once "vendor/autoload.php";	
	$collection = (new MongoDB\Client)->POS->Product;
	$result_first = $collection->findOne([],['sort' => ['_id' => 1]]);
	$result_last = $collection->findOne([],['sort' => ['_id' => -1]]);
	if ($result_first)
	{
		$myObj=new \stdClass();
		$myObj->first_ID = (string)$result_first['_id'];
		$myObj->last_ID = (string)$result_last['_id'];		
		echo json_encode($myObj);
	}
?>