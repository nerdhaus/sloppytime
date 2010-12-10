<?php
// $Id$

/**
 * Implementation of hook_views_plugins().
 */
function sloppy_time_views_plugins() {
  return array(
    'cache' => array(
      'sloppy_time' => array(
        'path' => drupal_get_path('module', 'sloppy_time') . '/views',
        'parent' => 'time',
        'title' => t('Sloppy time'),
        'help' => t('Time-based caching with random slop.'),
        'handler' => 'sloppy_time_plugin_cache',
        'uses options' => TRUE,
      ),
    ),
  );
}