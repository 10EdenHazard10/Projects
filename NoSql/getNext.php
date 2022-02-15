<?php
	$_id = $_REQUEST['_id'];
	require_once "../vendor/autoload.php";	
	$collection = (new MongoDB\Client)->POS->Product;
	$result = $collection->findOne(['_id' => ['$gt' => new MongoDB\BSON\ObjectID($_id)]],['sort' => ['_id' => 1]]);
	if ($result)
	{
		$myObj=new \stdClass();
		$myObj->_id = (string)$result['_id'];
		$myObj->Code = $result['code'];
		$myObj->Name = $result['name'];
		$myObj->Cost = $result['cost'];
		$myObj->Price = $result['price'];
		$myObj->Onhand = $result['onhand'];
		$myObj->vendors = $result['vendors'];
		echo json_encode($myObj);
	}
?>