<?php

require_once drupal_get_path('module', 'gmail_api') . '/../libraries/google-api-php-client/vendor/autoload.php';

function gmail_api_get_client() {
  $client = new Google_Client();
  $client->setClientId(variable_get('gmail_api_client_id', ''));
  $client->setClientSecret(variable_get('gmail_api_client_secret', ''));
  $client->setRedirectUri(url('gmail-api/oauth2callback', array('absolute' => TRUE)));
  $client->addScope(Google_Service_Gmail::GMAIL_SEND);
  $client->setAccessType('offline');
  return $client;
}

function gmail_api_oauth_callback() {
  $client = gmail_api_get_client();
  if (!empty($_GET['code'])) {
    $client->fetchAccessTokenWithAuthCode($_GET['code']);
    $_SESSION['gmail_access_token'] = $client->getAccessToken();
    drupal_set_message(t('Gmail 授權完成'));
    drupal_goto('admin/config/services/gmail-api');
  } else {
    drupal_set_message(t('授權失敗'), 'error');
  }
}

