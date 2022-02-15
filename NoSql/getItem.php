<?php 
		
	require_once "../vendor/autoload.php";	
	$code = $_POST['m_code'];
	$decodedProduct = json_decode($code, true);
	
	$collection = (new MongoDB\Client)->POS->Product;
	
	$result = $collection->findOne(['code' => $code], []);
	
	if ($result)
	{
		$myObj=new \stdClass();
		
		$myObj->Name = $result['name'];
		$myObj->Unit = $result['price'];
		echo json_encode($myObj);
	}
	else
	{
		$myObj=new \stdClass();
		$myObj->Name = '';
		echo json_encode($myObj);
	}

?>