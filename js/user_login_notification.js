(function ($) {
    Drupal.behaviors.user_login_notification = {
        attach: function (context, settings) {
            var hide_user_login_notification = function (context) {
                $('.block-user-login-notification').slideUp();
            };
            setTimeout(hide_user_login_notification, 10000); //TODO: Add this time to Drupal settings via a variable
        }
    };
})(jQuery);