<?php

	require_once "../vendor/autoload.php";	
	$myItem = $_REQUEST['m_code'];
	
	
	$collection = (new MongoDB\Client)->POS->Product;
	$item_regex = new MongoDB\BSON\Regex($myItem, 'i');
	
	
	$result = $collection->find(['name' => $item_regex], []);
	
	
	


	foreach($result as $row) {
		$arr_out[] = $row;
	}
	if (isset($arr_out)){
		echo json_encode($arr_out);
		return;
	}
	else
	{
		echo "X";
		return ;
	}

?>