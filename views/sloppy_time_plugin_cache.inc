<?php
// $Id$

/**
 * Simple caching of query results for Views displays; adds roughly one minute
 * of "slop" to time comparisons, allowing large numbers of views to expire at
 * at different times even if they were populated at the same time and share the
 * same lifespan.
 */
class sloppy_time_plugin_cache extends views_plugin_cache_time {
  function summary_title() {
    return "Sloppy time cache";
  }

  /**
   * Return the expiry time for this cache plugin.
   */
  function cache_expire($type) {
    if ($lifespan = $this->options[$type . '_lifespan']) {
      $cutoff = time() - $lifespan + rand(0, 60);
      return $cutoff;
    }
    else {
      return FALSE;
    }
  }
}