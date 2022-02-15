<?php
	
	require_once "../vendor/autoload.php";	
	$collection = (new MongoDB\Client)->POS->Product;
	#$result = $collection->findOne(['_id' => ['$gt' => new MongoDB\BSON\ObjectID($_id)]],['sort' => ['_id' => 1]]);
	$result = $collection->distinct('vendors');
	echo json_encode($result);
	
	
	
?>

