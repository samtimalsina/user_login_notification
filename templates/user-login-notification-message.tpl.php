<?php
echo $variables['personalized_message'];
if ($variables['last_login']) {
  echo ":" . $variables['last_login'];
}