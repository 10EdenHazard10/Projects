

var transaction = new Array();  //used in the sales screen
var ProductSearch = new Array();  //used in the pick a product screen

var summary = 0;
var selected_index;
var product_index = -1;

/***************************************************************************
		             START OF POS SALES SCREEN FUNCTIONS
****************************************************************************/
function init(){
	var mytable = "<table><thead><tr><th>Code</th><th>Product Name</th><th>Unit</th><th>Qty</th><th>Total</th></tr></thead></table>";		
	document.getElementById("table").innerHTML = mytable;
	setCurrent("POS");
}
function add_item(pcode,q,pna,pp)
	{			
		
		if (pna == "Product Not Found!")
		{
			alert("Product not found!");
			return;
		}
		if (pcode == '')
		{
			alert("Product not found!");
			return;
		}
		if (typeof q === "undefined") 
		{
			q = 1;			
		}
		if (typeof q === "string" && q == '') 
		{
			q = 1;			
		}	
		
		$("table").html = "";		
		var theID = "";		
		//var mytable = "<table id='DataTable'><thead><tr><th>Code</th><th>Product Name</th><th>Unit</th><th>Qty</th><th>Total</th></tr></thead>";		
		summary += pp*q;
		transaction.unshift({ProdID : pcode, ProdName : pna, AmtSold : q,  UnitPrice : pp});
		selected_index = 0;
		refreshGrid();
		$("#table").animate({ scrollTop: 0 }, "fast");	
		document.getElementById("summary").style.display = "block";
		document.getElementById("summary").innerHTML = "$"+summary.toFixed(2);		
		document.getElementById('xpcode').value = '';
		document.getElementById('pname_nf').innerText = '';		
		document.getElementById('xpcode').focus();
		document.getElementById('save').style.display = "block";
		document.getElementById('cancel').style.display = "block";
		document.getElementById("inst").style.display = "block";		
	}
function saveit()
	{
		
		var sale = {
			'salesno': '',
			'salesdate': '',
			'salestotal': summary.toFixed(2),
			'items': transaction
		};
		m_sale = JSON.stringify(sale);
		$.post("addSale.php",{sale : m_sale},function(data){
				//alert("Sales number "+data+" saved successfully");
				window.location.reload(true);
			});
	}
function cancelit()
{
	window.location.reload(true);
}
//$(document).on("click", "body", function(e){
	//document.getElementById('xpcode').focus();
//});
$(document).on("keydown", "#xpcode", function(e){			
		if((e.which == 13) || (e.keyCode == 13)){
			var code = this.value;
			if (code)
			{						
				$.post("getitem.php",{m_code : code},function(data){	
					var parsedJSON = JSON.parse(data);
					if (parsedJSON.Name != '')
					{
						add_item(code,1,parsedJSON.Name,parsedJSON.Unit);
					}
					else
					{
						$("#pname_nf").html("Product Not Found!");									
					}
				});
			}		
        }			
        if((e.which == 38) || (e.keyCode == 38)){									
			selected_index--;
			if (selected_index < 0)
			{
				selected_index=0;
			}
			if (transaction.length == 0)
			{
					return;
			}
			refreshGrid();
			//if (selected_index > 5){
				var elmnt = document.getElementById("table");
				elmnt.scrollTop -= 40;
			//}				
						
        }
		if((e.which == 40) || (e.keyCode == 40)){									
			selected_index++;
			if (transaction.length == 0)
			{
					return;
			}			
			var transLen = transaction.length;
			if (selected_index > transLen-1)
			{
				selected_index = transLen-1;
			}	
			refreshGrid();
			if((selected_index > 4) && ( selected_index <= transLen-1))
			{
				var elmnt = document.getElementById("table");
				elmnt.scrollTop += 40;				
			}				
		}
		if((e.which == 39) || (e.keyCode == 39)){
			transaction[selected_index]["AmtSold"]++;
			refreshGrid();
		}	
		if((e.which == 37) || (e.keyCode == 37)){
			transaction[selected_index]["AmtSold"]--;
			refreshGrid();
		}	
    });
$(document).on('input', '#xpcode', function(e){
	var code = this.value;
	if (isNaN(code)) {
		if (code.length >= 2){
			modal.style.display = "block";
			document.getElementById('psearch').value = code;
			document.getElementById('psearch').focus();
			on_first_display(code);
		}
	}	
});

function refreshGrid()
{
	summary=0;
	var theID = "";			
	var mytable = "<table><tr><th>Code</th><th>Product Name</th><th>Unit</th><th>Qty</th><th>Total</th></tr>";					
	transaction.forEach(myFunction);			
	function myFunction(item, index) {											
		theID = "";
		summary += item.UnitPrice*item.AmtSold;		
		if (index == selected_index) 
		{						
			theID = "class = 'selected'";
		}
		mytable += "<tr "+theID+"> <td>" + item.ProdID + "</td><td class=pro_grid_name>" + item.ProdName + "</td><td>" + item.UnitPrice + "</td><td>" + item.AmtSold + "</td><td>" + (item.AmtSold*item.UnitPrice).toFixed(2) + "</td></tr>";			 
	}
	mytable += "</table>";		
	document.getElementById("table").innerHTML = mytable;
	document.getElementById("summary").innerHTML = "$"+summary.toFixed(2);	
}

/***************************************************************************
		             END OF SALES SCREEN FUNCTIONS
****************************************************************************/


/***************************************************************************
		             START OF PICK-A-PRODUCT SCREEN FUNCTIONS
****************************************************************************/



$(document).on('input', '#psearch', function(e){
	var code = this.value;
	ProductSearch.length = 0;
	$.post("getProdName.php",{m_code : code},function(data){
		if (data == "X"){
			ProductSearch.length = 0;
			refreshProductGrid();
			return;
		}
		var parsedJSON = JSON.parse(data);		
		$.each(parsedJSON, function(key, item) {
			ProductSearch.push({ProdID : item.code, ProdName : item.name, ProdPrice : item.price});
		});	
	product_index = 0;	
	refreshProductGrid();	
	});	
});
$(document).on("keydown", "#psearch", function(e){			
		if((e.which == 13) || (e.keyCode == 13)){
			if (ProductSearch.length <= 0){
				return;
			}
			var x = sessionStorage.getItem("currentPage");
			if (x == "POS")
			{
				add_item(ProductSearch[product_index]["ProdID"],1,ProductSearch[product_index]["ProdName"],ProductSearch[product_index]["ProdPrice"]);
				document.getElementById('psearch').value = "";
				document.getElementById("pro_table").innerHTML = "";
				modal.style.display = "none";
				document.getElementById('xpcode').focus();
			}
			if (x == "PROD")
			{
				search(ProductSearch[product_index]["ProdID"]);
				document.getElementById('psearch').value = "";
				document.getElementById("pro_table").innerHTML = "";
				modal.style.display = "none";
			}

        }			
        if((e.which == 38) || (e.keyCode == 38)){									
			product_index--;
			if (product_index < 0)
			{
				product_index=0;
			}
			if (ProductSearch.length == 0)
			{
					return;
			}
			refreshProductGrid();	
        }
		if((e.which == 40) || (e.keyCode == 40)){									
			product_index++;
			if (ProductSearch.length == 0)
			{
					return;
			}			
			var transLen = ProductSearch.length;
			if (product_index > transLen-1)
			{
				product_index = transLen-1;
			}	
			refreshProductGrid();
		}	
    });
function on_first_display(code){
	ProductSearch.length = 0;
	$.post("getProdName.php",{m_code : code},function(data){
		if (data == "X"){
			ProductSearch.length = 0;
			refreshProductGrid();
			return;
		}
		var parsedJSON = JSON.parse(data);		
		$.each(parsedJSON, function(key, item) {
			ProductSearch.push({ProdID : item.code, ProdName : item.name, ProdPrice : item.price});
		});	
	product_index = 0;	
	refreshProductGrid();	
	});
}
function refreshProductGrid()
{
	var theID = "";			
	var mytable = "<table id='pick'><tr><th>Product Name</th><th>Unit</th></tr>";						
	ProductSearch.forEach(myFunction);			
	function myFunction(item, index) {											
		theID = "";	
		if (index == product_index) 
		{						
			theID = "class = 'selected'";
		}
		mytable += "<tr "+theID+" onclick='rowClicked("+index+")'> <td>" + item.ProdName + "</td><td>" + item.ProdPrice + "</td></tr>";			 
	}
	mytable += "</table>";
	document.getElementById("inst_search").style.display = "block";
	document.getElementById("pro_table").innerHTML = mytable;
}
function rowClicked(index){
	product_index = index;
	var x = sessionStorage.getItem("currentPage");
	if (x == "POS")
		{
			add_item(ProductSearch[product_index]["ProdID"],1,ProductSearch[product_index]["ProdName"],ProductSearch[product_index]["ProdPrice"]);
			document.getElementById('psearch').value = "";
			document.getElementById("pro_table").innerHTML = "";
			document.getElementById("inst_search").style.display = "none";
			modal.style.display = "none";
			document.getElementById('xpcode').focus();
		}
	if (x == "PROD")
		{
			search(ProductSearch[product_index]["ProdID"]);
			document.getElementById('psearch').value = "";
			document.getElementById("inst_search").style.display = "none";
			document.getElementById("pro_table").innerHTML = "";
			modal.style.display = "none";
		}
}

function product_search(){
	modal.style.display = "block";
	document.getElementById('psearch').focus();
}

// Get the modal
var modal = document.getElementById("myModal");

// Get the button that opens the modal
var btn = document.getElementById("myBtn");

// Get the <span> element that closes the modal
var span = document.getElementById("close");

if (span != null){
// When the user clicks on <span> (x), close the modal
	span.onclick = function() {
	
	document.getElementById('psearch').value = "";
	document.getElementById("pro_table").innerHTML = "";
	document.getElementById("inst_search").style.display = "none";
	modal.style.display = "none";	
	var x = sessionStorage.getItem("currentPage");
	if (x == "POS")
		{
		document.getElementById('xpcode').focus();
		}
	if (x == "PROD")
		{
		document.getElementById('pcode').focus();
		}
	}
}

// When the user clicks anywhere outside of the modal, close it
//window.onclick = function(event) {
  //if (event.target == modal) {
    //modal.style.display = "none";
  //}
//}
/***************************************************************************
		             END OF PICK-A-PRODUCT SCREEN FUNCTIONS
****************************************************************************/




/***************************************************************************
		             START OF PRODUCT SCREEN FUNCTIONS
****************************************************************************/


function pro_last(){
	$.get("getLast.php",function(data){
				updateTextBoxes(data);				
			});
	
}
function pro_first(){
	$.get("getFirst.php",function(data){
				updateTextBoxes(data);				
			});
}
function pro_prev(){	
    var x = sessionStorage.getItem("_id");
	if (x == 0){
		return;
	}
	if (x == sessionStorage.getItem("first_ID"))
	{
		alert("This is the first document in the collection.");
		return;
	}
	$.post("getPrev.php",{_id : x},function(data){				
		updateTextBoxes(data);		
	});
		
}
function pro_next(){
	var x = sessionStorage.getItem("_id");
	if (x == 0){
		return;
	}
	if (x == sessionStorage.getItem("last_ID"))
	{
		alert("This is the last document in the collection.");
		return;
	}
	$.post("getNext.php",{_id : x},function(data){
		updateTextBoxes(data);		
	});
}
function pro_saveit(){
	var pcode = document.getElementById('pcode').value;
	var pname = document.getElementById('pname').value;
	var pcost = document.getElementById('pcost').value;
	var pprice = document.getElementById('pprice').value;
	var ponhand = document.getElementById('onhand').value;	
	var pvendors = document.getElementById('vendors').value;
	pvendors = pvendors.replace(/, /g, ',');
	pvendors = pvendors.split(',');
	if (document.getElementById('psave').value == "Save")
	{
	    var product = {
			'code': pcode,
			'name': pname,
			'cost': pcost,
			'price': pprice,
			'onhand' : ponhand,
			'vendors' : pvendors
		};
		var productStr = JSON.stringify(product);		
		$.post("addProduct.php",{product : productStr},function(data){
				first_last();
				pro_cancelit();
			});
	}
	else
	{
		var x = sessionStorage.getItem("_id"); 
		var product = {
			'_id' : x,
			'code': pcode,
			'name': pname,
			'cost': pcost,
			'price': pprice,
			'onhand' : ponhand,
			'vendors' : pvendors
		};
		var productStr = JSON.stringify(product);		
		$.post("updateProduct.php",{product : productStr},function(data){
				pro_cancelit();
			});
	}
}
function search(code){
	$.post("getproduct.php",{m_code : code},function(data){	
		var parsedJSON = JSON.parse(data);
		if (parsedJSON.Name != '')
		{
			sessionStorage.setItem("_id",parsedJSON['_id']);
			document.getElementById('pcode').value = parsedJSON['Code'];
			document.getElementById('pname').value = parsedJSON['Name'];
			document.getElementById('pcost').value = parsedJSON['Cost'];
			document.getElementById('pprice').value = parsedJSON['Price'];
			document.getElementById('onhand').value = parsedJSON['Onhand'];
			document.getElementById('vendors').value = parsedJSON['vendors'];
			document.getElementById('psave').value = "Update";
		}
	});
	
}
	
function pro_cancelit(){
	document.getElementById('pcode').value = "";
	document.getElementById('pname').value = "";
	document.getElementById('pcost').value = "";
	document.getElementById('pprice').value = "";
	document.getElementById('onhand').value = "";
	document.getElementById('vendors').value = "";
	document.getElementById('psave').value = "Save";
	document.getElementById('pcode').focus();
	sessionStorage.setItem("_id",0);
	
}
function pro_deleteit(){
	var x = sessionStorage.getItem("_id");
	if(x == 0){
		alert("No document to delete.");
		return;
	}
	if (confirm("Are you sure you want to delete this document?") == true)
	{
		$.post("deleteProduct.php",{_id : x},function(data){
				first_last();
				pro_cancelit();				
			});
	}
}

function updateTextBoxes(data)
{
	var parsedJSON = JSON.parse(data);
	sessionStorage.setItem("_id",parsedJSON['_id']);
	document.getElementById('pcode').value = parsedJSON['Code'];
	document.getElementById('pname').value = parsedJSON['Name'];
	document.getElementById('pcost').value = parsedJSON['Cost'];
	document.getElementById('pprice').value = parsedJSON['Price'];
	document.getElementById('onhand').value = parsedJSON['Onhand'];
	document.getElementById('vendors').value = parsedJSON['vendors'];
	document.getElementById('psave').value = "Update";
}

function first_last(){
	$.get("first_last.php",function(data){
		var parsedJSON = JSON.parse(data);
		sessionStorage.setItem("first_ID",parsedJSON['first_ID']);
		sessionStorage.setItem("last_ID",parsedJSON['last_ID']);			
	});
	setCurrent("PROD");				
}
function getUniqueVendors(){
	$.get("getUniqueVendors.php",function(data){
			var parsedJSON = JSON.parse(data);
			var select = document.getElementById('vendor')
			select.options[0] = new Option("");	
			for(i=0;i<parsedJSON.length;i++){                   
                   select.options[select.options.length] = new Option(parsedJSON[i]);
              }	
		});
}

/***************************************************************************
		             END OF PRODUCT SCREEN FUNCTIONS
****************************************************************************/

/***************************************************************************
		             START OF MISCELLANEOUS FUNCTIONS
****************************************************************************/


function setCurrent(page){
	sessionStorage.setItem("currentPage",page);
}
/*
function tableText() {
  alert(this.innerHTML);
}

var cells = document.querySelectorAll("td")

for (var i = 0; i < cells.length; i++){
  cells[i].addEventListener("click", tableText)
}
*/