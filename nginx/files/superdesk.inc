    location /superdesk/ws {
        proxy_pass http://localhost:5100/;
        proxy_redirect http://$host/ /superdesk/ws/;
        proxy_http_version 1.1;
        proxy_buffering off;
        proxy_read_timeout 3600;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection "Upgrade";
    }

    location /superdesk/api {
        proxy_pass http://localhost:5000/api;
        proxy_set_header Host $HOST;
        expires epoch;
    
        sub_filter_once off;
        sub_filter_types application/json;
        sub_filter 'http://localhost' 'http://$host';
    }

    location /superdesk/contentapi {
        proxy_pass http://localhost:5400;
        proxy_redirect http://$host/ /superdesk/contentapi/;
        proxy_set_header Host $HOST;
        expires epoch;
    }

    location /superdesk/.well-known {
        root /var/tmp;
    }
    location /superdesk {
        alias /opt/superdesk/client/dist;

        # TODO: use "config.js:server" for user installations
        sub_filter_once off;
        sub_filter_types application/javascript;
        sub_filter 'http://localhost' 'http://$host/superdesk';
        sub_filter '/images/' 'http://$host/superdesk/images/';
        sub_filter 'ws://localhost/ws' 'ws://$host/superdesk/ws';
    }
