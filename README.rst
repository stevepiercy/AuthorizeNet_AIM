AuthorizeNet_AIM - Payment processing tag for Lasso Professional 8 and the Authorize.Net AIM v3.1 payment processing gateway
############################################################################################################################

:date: 2006-10-06 09:34
:modified: 2014-05-28 04:35:10
:tags: AuthorizeNet_AIM, Lasso, eCommerce, payment gateway
:category: Lasso
:slug: lasso-authorizenet-aim
:author: Steve Piercy
:description: AuthorizeNet_AIM - Payment processing tag for Lasso Professional 8 and the Authorize.Net AIM v3.1 payment processing gateway
:_url: index.html
:_save_as: index.html
:_status: hidden
:summary: Payment processing tag for Lasso Professional 8 and the Authorize.Net AIM v3.1 payment processing gateway…

The project `AuthorizeNet_AIM <https://github.com/stevepiercy/AuthorizeNet_AIM>`_
and its source files are hosted on GitHub.

Description
===========

This tag is an update to the `AuthorizeNet_AIM
<https://github.com/stevepiercy/AuthorizeNet_AIM>`_ payment processing tag for
Lasso 8 and the new Authorize.Net AIM v3.1 payment processing gateway.

This tag has one required parameter, ``-AIMParams``, and two optional
parameters, ``-testdeveloper`` and ``-testrequest``.

``-AIMParams`` is an unnamed map of name/value pairs representing the
parameters to be passed to Authorize.Net.

``-testdeveloper`` is a boolean that when ``TRUE`` submits a test transaction
to Authorize.Net's "test" URL.  Default is ``FALSE``.

``-testrequest`` is a boolean that when ``TRUE`` submits a test transaction
request to the designated URL ("test" or "secure") as set in the tag
configuration or by the ``-testdeveloper`` keyword parameter.  Default is
``FALSE``.

This tag returns a value which is either a string or a map.

* If the returned value is a string, the string is a plain text error message
  returned by Authorize.Net indicating that you have not properly configured
  the Authorize.Net Merchant Interface or this tag's settings.
* If the returned value is a map, it contains the key/value pairs of non-empty
  parameters in the response returned by the Authorize.Net gateway.

Support Free and Open Source Software Contributions
===================================================

If you like this tag or documentation, or think I need to spend less time at
the computer and take my wife out on a date night, then consider sending
either a recurring donation via `GitTip
<https://www.gittip.com/stevepiercy/>`_ for as small as 25¢ per week, or a
one-time donation via `PayPal
<https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=web%40stevepiercy%2ecom&lc=US&item_name=Steve%20Piercy%20%2d%20Website%20Builder&item_number=spwb&currency_code=USD&bn=PP%2dDonationsBF%3adonate_now%2epng%3aNonHosted>`_.

.. raw:: html

    <div class="row">
        <div class="small-6 columns text-center">
            <p>GitTip</p>
            <script data-gittip-username="stevepiercy"
        src="//gttp.co/v1.js"></script>
        </div>
        <div class="small-6 columns text-center">
            <p>PayPal</p>
            <form action="https://www.paypal.com/cgi-bin/webscr" method="post" target="_top">
                <input type="hidden" name="cmd" value="_s-xclick">
                <input type="hidden" name="encrypted" value="-----BEGIN PKCS7-----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-----END PKCS7-----">
                <input type="image" src="http://www.stevepiercy.com/images/donate_now.png" border="0" name="submit" alt="PayPal - The safer, easier way to pay online!">
                <img alt="Donate Now" border="0" src="https://www.paypalobjects.com/en_US/i/scr/pixel.gif" width="1" height="1">
            </form>
        </div>
    </div>

Duke accepts donations of biscuits and cabbages.  woof.

Usage
=====

It is highly recommend to store the ``AuthorizeNet_AIM`` tag in a location on
your web server that cannot be served, preferably outside of your web root.
You do *not* want your login or transaction key to be served as a plain text
file.

1. Configure
------------

In your page that calls ``[AuthorizeNet_AIM]``, build a map of parameters to
send to the tag.

.. code-block:: lasso

    var('AIMParams') = map(
        'x_first_name'	= $first_name,
        'x_last_name'	= $last_name,
        'x_amount'		= $amount,
    ... and so on...);

2. Set a variable to the method
-------------------------------

When calling ``[AuthorizeNet_AIM]``, store the results in a variable.  This
will allow you to easily code logic in your page to take appropriate action
based on the results (Response Code, etc.) from Authorize.Net.

.. code-block:: lasso

    var('aim_results') = AuthorizeNet_AIM($AIMParams);

Optionally, use the following following parameters.

``-testdeveloper=TRUE`` submits a test transaction to Authorize.Net's "test"
URL.  Default is ``FALSE``.

``-testrequest=TRUE`` submits a test transaction request to the designated URL
("test" or "secure") as set in the tag configuration or by the
``-testdeveloper`` keyword parameter.  Default is ``FALSE``.

The following sends a map of parameters to the tag, which posts the parameters
to Authorize.Net's test server as a test transaction request.

.. code-block:: lasso

	var('aim_results') = AuthorizeNet_AIM(
	    $AIMParams,
	    -testdeveloper=TRUE,
	    -testrequest=TRUE);

3. Sample page logic
--------------------

.. code-block:: lasso

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

4. Sample message
-----------------

I recommend displaying a simple error message *"Your request could not be
processed.  Please contact us at _____ during normal business hours."*  Don't
encourage users to try again because it will just frustrate them, or possibly
cause much worse problems (multiple payments, trigger an over limit event,
trigger a fraud alert with the card issuer, etc.).  And in the case of actual
fraud, you don't want to tip off the fraudster of why the transaction was
declined.

.. code-block:: lasso

    $sample_msg->append('Thank you, ' + $aim_results->find('x_first_name')
        + '!  You have personally enriched me by $'
        + $aim_results->find('x_amount') + '.');

5. Custom labels
----------------

You can add merchant-defined results labels to ``#aimresultlabels``, and
access them after they are echoed by Authorize.Net.

6. Summary
----------

Here is a code sample that sends an authorize-only transaction to the
Authorize.Net test server.

.. code-block:: lasso

    [
    var('AIMParams') = map(
        'x_login'='ENTER_YOUR_LOGIN',
        'x_tran_key'='ENTER_YOUR_TRANSACTION_KEY',
        'x_type'='auth_only',
        'x_card_num'='5424000000000015',    // dummy CC#
        'x_exp_date'='1220',                // December 2020
        'x_amount'='0.01');

    var('results') = authorizenet_aim($AIMParams,-testdeveloper=true);
    $results;
    ]

See the comments embedded in the tag's code for proper configuration.

For rapid testing:

* Copy the files ``AuthorizeNet_AIM.inc`` and ``AuthorizeNet_AIM.lasso`` to
  your web server.
* Configure settings in both files accordingly.  The settings in the latter
  override the former.
* Save and load ``AuthorizeNet_AIM.lasso`` to see the results.

Additional eCommerce Resources
------------------------------

The following information does not constitute an endorsement, warranty or
guarantee of service.  This information is provided for the sake of
comparison.  These are the lowest fees I have found over the years.

For further information on developing for AIM, download the `AIM Guide
<http://www.Authorize.Net/support/AIM_guide.pdf>`_.

You can sign up for a `developer sandbox account
<https://developer.Authorize.Net/sandbox/>`_, or you can have the client
purchase their own `Authorize.Net payment gateway account
<https://ems.Authorize.Net/oap/home.aspx?SalesRepID=39&ResellerID=11937>`_ and
create a "webmaster" user that has the required access.

In addition to this tag, the following are requirements.

#. Dedicated IP for SSL (~$10/month).
#. SSL.
#. `Secure certificate <http://www.namecheap.com/?aff=26253>`_ (starting at
   $10/year from NameCheap.com)
#. `Merchant account <http://www.takecardstoday.com/index.php?partner=100434>`_
   that accepts payments over the Internet.  Some brick and mortar retailers
   already have a merchant account, so sometimes it is easier to add this
   feature to their existing merchant account. If you need a merchant account,
   you can support the continued development of the ``AuthorizeNet_AIM`` tag
   using my `referral link <http://www.takecardstoday.com/index.php?partner=100434>`_.
   As of May 28, 2014, the merchant account costs $8.95/month (for a statement
   fee), plus 2.14% of the transaction amount and 24¢ per transaction.
   Everything else is free.
#. payment gateway (an Authorize.Net account, for example). I am an
   Authorize.Net account reseller. You can support the continued development
   of the ``AuthorizeNet_AIM`` tag by following my `reseller link
   <https://ems.Authorize.Net/oap/home.aspx?SalesRepID=39&ResellerID=11937>`_.
   As of May 28, 2014, the cost is $17.95/month, plus $99.00 account setup,
   plus $0.10 per transaction.

I am available as a consultant for ecommerce solutions. Please visit `Services
</services/>`_ for more information.
