[
include('AuthorizeNet_AIM.inc');

var('AIMParams') = map(
    'x_login'='XXXXXXXXXXXXX',          // configure
    'x_tran_key'='XXXXXXXXXXXXX',
    'x_type'='auth_only',
//  'x_type'='prior_auth_capture',
//  'x_trans_id'='someid',
    'x_card_num'='5424000000000015',    // dummy CC#
    'x_exp_date'='1220',                // December 2020
    'x_amount'='0.01');

var('results') = authorizenet_aim(
    $AIMParams,
    -testdeveloper=true,    // change as needed
    -testrequest=false,     // change as needed
    -curl=true,             // change as needed
    -tlsv12=true,           // change as needed
);
]
<textarea rows="40" cols="80">[$results]</textarea>
