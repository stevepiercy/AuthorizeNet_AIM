AuthorizeNet_AIM
================

Payment processing tag for Lasso 8 and the Authorize.net AIM v3.1 payment processing gateway.

Description
-----------

This tag is an update to the AuthorizeNet_AIM payment processing tag for Lasso 8 and the new Authorize.net AIM v3.1 payment processing gateway.

This tag has one required parameter, `-AIMParams`, and two optional parameters, `-testdeveloper` and `-testrequest`.

`-AIMParams` is an unnamed map of name/value pairs representing the parameters to be passed to Authorize.Net.

`-testdeveloper` is a boolean that when `TRUE` submits a test transaction to Authorize.Net's "test" URL.  Default is `FALSE`.

`-testrequest` is a boolean that when `TRUE` submits a test transaction request to the designated URL ("test" or "secure") as set in the tag configuration or by the `-testdeveloper` keyword parameter.  Default is `FALSE`.

This tag returns a value which is either a string or a map.  If the returned value is a string, the string is a plain text error message returned by Authorize.Net indicating that you have not properly configured the Authorize.Net Merchant Interface or this tag's settings.  If the returned value is a map, it contains the key/value pairs of non-empty parameters in the reponse returned by the Authorize.Net gateway.

Support Free and Open Source Software Contributions
---------------------------------------------------

If you like this tag or documentation, or think I need to spend less time at the computer and take my wife out on a date night, then consider sending either a recurring donation via [GitTip](https://www.gittip.com/stevepiercy/) for as small as 25¢ per week, or a one-time donation via [PayPal](https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=web%40stevepiercy%2ecom&lc=US&item_name=Steve%20Piercy%20%2d%20Website%20Builder&item_number=spwb&currency_code=USD&bn=PP%2dDonationsBF%3adonate_now%2epng%3aNonHosted).

Duke accepts donations of biscuits and cabbages.  woof.


Usage
-----

It is highly recommend to store this file on your web server in a location that cannot be served, preferably outside of your web root.  You do *not* want your login or transaction key to be served as a plain text file.

###1. Configure

In your page that calls [AuthorizeNet_AIM], build a map of parameters to send to the tag.

    var('AIMParams') = map(
        'x_first_name'	= $first_name,
        'x_last_name'	= $last_name,
        'x_amount'		= $amount,
    ... and so on...);

###2. Set a variable to the method

When calling [AuthorizeNet_AIM], store the results in a variable.  This will allow you to easily code logic in your page to take appropriate action based on the results (Response Code, etc.) from Authorize.net.

    var('aim_results') = AuthorizeNet_AIM($AIMParams);

Optionally, use the following following parameters:

`-testdeveloper=TRUE` submits a test transaction to Authorize.Net's "test" URL.  Default is `FALSE`.

`-testrequest=TRUE` submits a test transaction request to the designated URL ("test" or "secure") as set in the tag configuration or by the `-testdeveloper` keyword parameter.  Default is `FALSE`.

The following sends a map of parameters to the tag, which posts the parameters to Authorize.net's test server as a test transaction request.

	var('aim_results') = AuthorizeNet_AIM($AIMParams,-testdeveloper=TRUE,-testrequest=TRUE);

###3. Sample page logic

    // evaluate results and make appropriate decisions
    if($aim_results->find('x_response_code') == '1');
        // transaction approved
    else;
        // transaction failed
        select($aim_results->find('x_response_code'));
            case('2');
                //  declined
            case('3');
                //  transaction processing error
            case('4');
                //  held for review
            case;
                //  undefined error
        /select;
    /if;

###4. Sample message

I recommend displaying a simple error message "Your request could not be processed.  Please contact us at `_____` during normal business hours."  Don't encourage them to try again because it will just frustrate them, or possibly cause much worse problems (multiple payments, trigger an over limit event, trigger a fraud alert with the card issuer, etc.).  And in the case of actual fraud, you don't want to tip off the fraudster of why the transaction was declined.

    $sample_msg->append('Thank you, ' + $aim_results->find('x_first_name')
        + '!  You have personally enriched me by $'
        + $aim_results->find('x_amount') + '.');

###5. Custom labels

You can add merchant-defined results labels to `#aimresultlabels`, and access them after they are echoed by Authorize.Net.

###6. Summary

Here is a code sample that sends an authorize-only transaction to the Authorize.Net test server.

    [
    var('AIMParams') = map(
        'x_login'='ENTER_YOUR_LOGIN',
        'x_tran_key'='ENTER_YOUR_TRANSACTION_KEY',
        'x_type'='auth_only,
        'x_card_num'='5424000000000015',    // dummy CC#
        'x_exp_date'='1220',                // December 2020
        'x_amount'='0.01');

    var('results') = authorizenet_aim($AIMParams,-testdeveloper=true);
    $results;
    ]

For rapid testing:

* Create a new file.
* Paste the `AuthorizeNet_AIM` tag into it.
* Copy the snippet above, and paste it after the tag.
* Save and load the page to see the results.

See the comments embedded in the tag's code for proper configuration.

Additional eCommerce Resources
------------------------------

The following information does not constitute an endorsement, warranty or guarantee of service.  This information is provided for the sake of comparison.  These are the lowest fees I have found over the years.

For further information on developing for AIM, download the [AIM Guide](http://www.authorize.net/support/AIM_guide.pdf).

You can sign up for a [developer sandbox account](https://developer.authorize.net/sandbox/), or you can have the client purchase their own [Authorize.Net payment gateway account](https://ems.authorize.net/oap/home.aspx?SalesRepID=39&ResellerID=11937) and create a "webmaster" user that has the required access.

In addition to this tag, the following are requirements.

1. Dedicated IP for SSL (~$10/month).
1. SSL.
1. [Secure certificate](http://www.namecheap.com/?aff=26253) (starting at $10/year from NameCheap.com)
1. [Merchant account](http://www.takecardstoday.com/index.php?partner=100434) that accepts payments over the Internet.  Some brick and mortar retailers already have a merchant account, so sometimes it is easier to add this feature to their existing merchant account.  If you need a merchant account, you can support the continued development of the `AuthorizeNet_AIM` tag using my [referral link](http://www.takecardstoday.com/index.php?partner=100434). As of May 28, 2014, the merchant account costs $8.95/month (for a statement fee), plus 2.14% of the transaction amount and 24¢ per transaction.  Everything else is free.
1. payment gateway (an Authorize.Net account, for example). I am an Authorize.net account reseller. You can support the continued development of the AuthorizeNet_AIM tag by following my [referral link]([Authorize.Net payment gateway account](https://ems.authorize.net/oap/home.aspx?SalesRepID=39&ResellerID=11937)). As of May 28, 2014, the cost is $17.95/month, plus $99.00 account setup, plus $0.10 per transaction.

I am available as a consultant for ecommerce solutions.  Please visit [my website](http://www.stevepiercy.com/services/) for more information.

