[
define_tag(
    'authorizenet_aim',
    -required='AIMParams',
    -criteria=(#AIMParams -> type == 'map'),
    -optional='testdeveloper', -type='boolean',
    -optional='testrequest', -type='boolean',
    -optional='curl', -type='boolean',
    -optional='tlsv12', -type='boolean',
    -description = 'Sends a map of parameters to Authorize.Net for transaction processing, and returns the response of the transaction.');

/*

==================
CONFIGURATION
==================

Configuration includes configuring the Authorize.Net website Merchant Interface, setting values in this tag, and passing values into this tag as a map of key/values.

In the Authorize.Net Merchant Interface, obtain your transaction key.

    Account > Settings > API Login ID and Transaction Key

You will enter your transaction key below.

Next configure the response delimiter character.

    Account > Settings > Direct Response

Use a pipe and no encapsulation characters:

Delimited Response: (X) Yes    ( ) No
Default Field Separator     | (pipe)  or [ ]
Field Encapsulation Character   [blank] or  [ ]

If you do not use the above settings then you must change the corresponding values as defined elsewhere in this tag.

Now enter configuration values for this tag below.

You can choose to either set configuration values in this tag below or pass them in as values in the map of AIM parameters.  Any values passed into this tag will override their corresponding values entered below.

*/
    // Your API login ID for the payment gateway account
    local('x_login') = 'ENTER_YOUR_LOGIN';

    // Your transaction key obtained from the Merchant Interface
    local('x_tran_key') = 'ENTER_YOUR_TRANSACTION_KEY';

    // Most transaction types will be AUTH_CAPTURE.
    // See the AIM Guide for other types and further requirements.
    local('x_type') = 'AUTH_CAPTURE';

// If any of the following values have not been passed into this tag via the map of AIM parameters, then insert the configured values above.
    #AIMParams -> find('x_login') == '' ? #AIMParams -> insert('x_login'=#x_login);
    #AIMParams -> find('x_tran_key') == '' ? #AIMParams -> insert('x_tran_key'=#x_tran_key);
    #AIMParams -> find('x_type') == '' ? #AIMParams -> insert('x_type'=#x_type);

// Initialize variables

    local(
        'CurrentParam'          = null,
        'AIMParamArray'         = array,
        'AIMParamstring'        = string,
        'AIMURL'                = string,
        'AIMResult'             = string,
        'AIMResultArray'        = array,
        'AIMResultLabelArray'   = array,
        'AIMCurrentResultLabel' = null,
        'curl_post_data'        = string,
        'output'                = null,
        );

    !local_defined('testdeveloper') ? local('testdeveloper') = false;
    !local_defined('curl') ? local('curl') = false;
    !local_defined('tlsv12') ? local('tlsv12') = false;

    // check for the existence of os_process and shell if curl is true
    if(#curl);
        fail_if(!lasso_tagexists('os_process'), -1000, '[os_process] is not installed and configured.');
        fail_if(!lasso_tagexists('shell'), -1000, '[shell] is not installed and configured.');
    /if;

/*
The following URL will be used to send your POST parameters to Authorize.Net.
'test' is used for testing your developer x_login and x_tran_key values, whereas 'secure' is used for testing your merchant account values.

Note that you can still submit test transactions to 'secure' either by setting the Authorize.Net merchant interface to TEST MODE or by submitting a transaction with the parameter 'x_test_request'='TRUE'.
*/
    if(#testdeveloper == true);
        #AIMURL = 'https://test.Authorize.Net/gateway/transact.dll';
    else;
        #AIMURL = 'https://secure2.authorize.net/gateway/transact.dll';
    /if;

    if(local_defined('testrequest'));
        if(#testrequest=='true');
            // Send a test transaction request to the designated server.
        #AIMParams -> insert('x_test_request'='TRUE');
        else;
            // Rely upon the TEST MODE configuration in the Authorize.Net Merchant Interface.  Omitting -testrequest is equivalent to setting it to FALSE.
            #AIMParams -> insert('x_test_request'='FALSE');
        /if;
    /if;

/*
The following commented parameters should be set through the merchant web interface on Authorize.Net and are placed here for reference only.  However, if you set a parameter in Authorize.Net, comment it below; and if you do not set a parameter in Authorize.Net, then uncomment it here.  In other words, define parameters in one and only one place.
*/

//  #AIMParams -> insert('x_test_request'='FALSE');
//  #AIMParams -> insert('x_version'='3.1');
//  #AIMParams -> insert('x_delim_data'='TRUE');

    #AIMParams -> insert('x_relay_response'='FALSE'); // Do not change

    iterate(#AIMParams, local('CurrentAIMParam'));
        #AIMParamArray -> insert((#CurrentAIMParam -> first)=(#CurrentAIMParam -> second));
        #curl ? #curl_post_data -> append(' -d ' + encode_url(#CurrentAIMParam -> first) + '=' + encode_url(#CurrentAIMParam -> second));
    /iterate;


// The first 68 result labels are reserved by the AIM gateway for version 3.1.  Do not alter their order or names.
    local('aimresultlabels') = array(
        'x_response_code',
        'x_response_subcode',
        'x_response_reason_code',
        'x_response_reason_text',
        'x_approval_code',
        'x_avs_result_code',
        'x_transaction_id',
        'x_invoice_num',
        'x_description',
        'x_amount',
        'x_method',
        'x_type',
        'x_cust_id',
        'x_first_name',
        'x_last_name',
        'x_company',
        'x_address',
        'x_city',
        'x_state',
        'x_zip',
        'x_country',
        'x_phone',
        'x_fax',
        'x_email',
        'x_ship_to_first_name',
        'x_ship_to_last_name',
        'x_ship_to_company',
        'x_ship_to_address',
        'x_ship_to_city',
        'x_ship_to_state',
        'x_ship_to_zip',
        'x_ship_to_country',
        'x_tax',
        'x_duty',
        'x_freight',
        'x_tax_exempt',
        'x_po_num',
        'x_MD5_hash',
        'x_card_code',
        'x_cavv_resp_code',
        '',
        '',
        '',
        '',
        '',
        '',
        '',
        '',
        '',
        '',
        'x_acct_number_last4',
        'x_card_type',
        'x_split_tender_id',
        'x_prepaid_requested_amount',
        'x_prepaid_balance_on_card',
        '',
        '',
        '',
        '',
        '',
        '',
        '',
        '',
        '',
        '',
        '',
        '',
        '',
// The following labels are optionally defined by the merchant and echoed by the AIM gateway.  If you do not add them here, they will not be echoed by the AIM Results Array and not added to the #output.
        'x_comments',
        'x_another_example');


// Send parameters to Authorize.Net.  Cross fingers.
    if(#curl);
        #AIMResult = string(shell('curl ' +#AIMURL + #curl_post_data + (#tlsv12 ? ' --tlsv1.2' | '')));
    else;
        #AIMResult = string(include_url(#AIMURL, -postparams=#AIMParamArray));
    /if;
/* 
The character used in the following split must be the same as the character you use in your Authorize.Net settings:

Account > Settings > Direct Response >  Direct Response Delimiter
*/
    #AIMResultArray = #AIMResult -> split('|');

    if(#AIMResultArray -> Size == 1);
// uh-oh.  There was a failure.  Check your configuration in the Merchant Interface or in this tag.
        #output = #AIMResult;
    else;
// Yippee!  The gateway returned a response we can parse to determine whether the transaction was successful or has failed.
        #output = map;
        iterate(#AIMResultArray, local('current_result'));
            if(#aimresultlabels -> size > loop_count);
// We are within the range of defined results labels.
                local('current_label' = #aimresultlabels -> get(loop_count));
                if(#current_result != '');
                    #output -> insert((#current_label)=(#current_result));
                /if;
            else;
// We are outside the range of defined results labels, and so we create ennumerated labels.
                local('current_label' = 'x_out_of_range_label_'+loop_count);
                if(#current_result != '');
                    #output -> insert((#current_label)=(#current_result));
                /if;
            /if;
        /iterate;
    /if;
    return(#output);
/define_tag;
]
