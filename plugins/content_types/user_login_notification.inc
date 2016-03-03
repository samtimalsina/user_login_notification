<?php
$plugin = array(
  'title' => t('User Login Notification'),
  'description' => t('Displays users last login date and time'),
  'single' => TRUE,
  'content_types' => array('user_login_notification'),
  'render callback' => 'user_login_notification_content_type_render',
  'required context' => new ctools_context_required(t('User'), 'user'),
  'edit form' => 'user_login_notification_content_type_edit_form',
  'category' => array(t('User Login'), -9),
);

/**
 * Ctools edit form.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function user_login_notification_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['custom_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom message'),
    '#description' => t('Custom message to use in the block.'),
    '#default_value' => !empty($conf['custom_message']) ? $conf['custom_message'] : 'You last logged in at',
  );
  return $form;
}

/**
 * Ctools edit form submit handler.
 *
 * @param $form
 * @param $form_state
 */
function user_login_notification_content_type_edit_form_submit($form, &$form_state) {
  foreach (array('custom_message') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Render callback function.
 *
 * @param $subtype
 * @param $conf
 * @param $args
 * @param $context
 * @return stdClass
 */
function user_login_notification_content_type_render($subtype, $conf, $args, $context) {
  $user = $context->data;
  $block = new stdClass();

  if ($user->uid == 0) {
    $block->content = theme('user_login_notification', array(
      'last_login' => FALSE,
      'personalized_message' => 'You are not logged in'
    ));
  } else {
    $block->content = theme('user_login_notification', array(
      'last_login' => format_date($user->login, 'custom', 'm/d/Y - H:i T', $user->timezone),
      'personalized_message' => $conf['custom_message']
    ));
  }
  return $block;
}