location /mail {
    alias $mails/;
    default_type text/plain;
    autoindex on;
    autoindex_exact_size off;
}
