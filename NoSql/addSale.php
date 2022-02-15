<?php
require_once "vendor/autoload.php";
$collection = (new MongoDB\Client)->POS->Sales;
$update = (new MongoDB\Client)->POS->Product;
$unique = $collection->findOneAndUpdate(
    [ 'field' => 'unique' ],
    [ '$inc' => [ 'unique_number' => 1 ]],
    [
		'upsert' => true,
        'returnDocument' => MongoDB\Operation\FindOneAndUpdate::RETURN_DOCUMENT_AFTER
    ]
);

 //Retrieve the string, which was sent via the POST parameter "user" 
$sale = $_POST['sale'];
//Decode the JSON string and convert it into a PHP associative array.
$decodedSale = json_decode($sale, true);
$decodedSale['salesno'] = $unique->unique_number;
$decodedSale['salesdate'] = new \MongoDB\BSON\UTCDateTime(time()*1000);





for ($x = 0; $x < sizeof($decodedSale['items']); $x++) {
	$decodedSale['items'][$x]['AmtSold'] = (int)$decodedSale['items'][$x]['AmtSold'];
	$decodedSale['items'][$x]['UnitPrice'] = (float)$decodedSale['items'][$x]['UnitPrice'];
	$decodedSale['items'][$x]['ProdName'] = (string)$decodedSale['items'][$x]['ProdName'];
	 
	$update->findOneAndUpdate(['name' => ($decodedSale['items'][$x]['ProdName'])], 
	['$inc' => [ 'onhand' => -($decodedSale['items'][$x]['AmtSold']) ]], []);
}

$decodedSale['salestotal'] = (float)$decodedSale['salestotal'];
$collection->insertOne($decodedSale);
echo $decodedSale['salesno'];
?>