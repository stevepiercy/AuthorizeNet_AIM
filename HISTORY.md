Version History: 1.6.0
======================
* Date: Nov 5, 2010
* Author: Steve Piercy
* URL: http://www.stevepiercy.com/
* URL: https://www.github.com/stevepiercy/AuthorizeNet_AIM

Modified to work with Lasso 9.

Added new Authorize.Net field labels for Partial Authorization Transactions.  This allows customers to use multiple transactions to cover the total amount of the order, e.g., gift card and credit card.  See the AIM Developer Guide for details.

Purged ugly variable declarations.

Version History: 1.5.2
======================
* Date: Feb 2, 2010
* Author: Steve Piercy
* URL: http://www.stevepiercy.com/
* URL: https://www.github.com/stevepiercy/AuthorizeNet_AIM

Disambiguated the parameter `-testrequest`.  Now setting it to `FALSE` or omitting it are equivalent.

Thanks to Marc Pinnell for pointing it out.

Version History: 1.5
====================
* Date: Jan 31, 2010
* Author: Steve Piercy
* URL: http://www.stevepiercy.com/
* URL: https://www.github.com/stevepiercy/AuthorizeNet_AIM

Now the developer can set values in the map of parameters for `x_login`, `x_tran_key` and `x_type`.  Any parameters in the map that are passed into the tag will override any values hard-coded in the tag, except `x_relay_response` which you should leave alone.

Provided even better code samples and usage example.

Thanks to Marc Pinnell for the suggestion and donation for Duke biscuits.

Version History: 1.4
====================
* Date: Jan 17, 2010
* Author: Steve Piercy
* URL: http://www.stevepiercy.com/
* URL: https://www.github.com/stevepiercy/AuthorizeNet_AIM

Added two new parameters:

`-testdeveloper=TRUE` submits a test transaction to Authorize.Net's "test" URL.  Default is `FALSE`.  Optional.

`-testrequest=TRUE` submits a test transaction request to the designated URL ("test" or "secure") as set in the tag configuration or by the `-testdeveloper` keyword parameter.  Default is `FALSE`.  Optional.

Thanks to Jason Huck for the suggestion and to Rick Dwyer for the donation for Duke biscuits.

Version History: 1.3
====================
* Date: Jan 28, 2009
* Author: Steve Piercy
* URL: http://www.stevepiercy.com/
* URL: https://www.github.com/stevepiercy/AuthorizeNet_AIM

Gave code a colostomy.  Ugly, yucky, dirty colons!

Improved usage guidelines documentation.

Version History: 1.2
====================
* Date: Sep 26, 2007
* Author: Steve Piercy
* URL: http://www.stevepiercy.com/
* URL: https://www.github.com/stevepiercy/AuthorizeNet_AIM

Added comments regarding AIM gateway response fields.

Improved usage guidelines documentation.

Corrected names of response labels for positions 39 and 40.

Added empty AIM 3.1 reserved fields for positions through 68.  May be used for future expansion of AIM.

Added check that compares the sizes of the `aimresultlabels` and `AIMResultArray` arrays to prevent "invalid position passed to get" error, and to generate enumerated labels for results that are out of range of the labels array.

Version History: 1.1
====================

* Date: Oct 6, 2006
* Author: Steve Piercy
* URL: http://www.stevepiercy.com/
* URL: https://www.github.com/stevepiercy/AuthorizeNet_AIM

Updated for Lasso 8.1 and AIM 3.1.  Thanks to Jonathan Guthrie for schooling me on iterate.

Version History: 1.0
====================

* Date: March 3, 2003
* Author: Trigger Consulting
* URL: http://www.trigger.biz/

Disclaimer
----------

While Trigger Consulting has made every effort to deliver a high quality product, we do not guarantee that this product is free from defects.  The software is provided "as is," and you use the software at your own risk. Trigger Consulting makes no warranties as to performance, merchantability, fitness for a particular purpose, or any other warranties whether expressed or implied. No oral or written communication from or information provided by Trigger Consulting shall create a warranty. Under no circumstances shall Trigger Consulting be liable for direct, indirect, special, incidental, or consequential damages resulting from the use, misuse, or inability to use this software, even if Trigger Consulting has been advised of the possibility of such damages. These exclusions and limitations may not apply in all jurisdictions. You may have additional rights and some of these limitations may not apply to you.

`AuthorizeNet_AIM` is in the public domain and free for your use. Obviously, Trigger Consulting would appreciate credit where credit is due. No pun intended.

