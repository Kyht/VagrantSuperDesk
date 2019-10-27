server {
        listen 80;
        listen [::]:80;
        server_name newsroom.DOMAIN.com;

        root /opt/newsroom;

    location /newsroom {
            proxy_pass http://localhost:5050/;
            proxy_redirect http://$host/ /newsroom/;
            expires epoch;
        sub_filter_once off;
            sub_filter_types application/javascript;
            sub_filter '/static/' '/newsroom/static/';
            sub_filter '/theme/' '/newsroom/theme/';
            sub_filter '/login/' '/newsroom/login/';
            sub_filter '/token/' '/newsroom/token/';
      }

}
