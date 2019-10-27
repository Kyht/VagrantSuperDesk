FROM phusion/baseimage:0.11

ENV PATH=/bin:/usr/bin:/usr/local/bin:/sbin:/usr/sbin:/usr/local/sbin

RUN apt-get update && apt-get upgrade -y -o Dpkg::Options::="--force-confold"

RUN /usr/bin/apt-get install -y wget openjdk-8-jre-headless
RUN /usr/bin/wget https://download.elastic.co/elasticsearch/release/org/elasticsearch/distribution/deb/elasticsearch/2.4.0/elasticsearch-2.4.0.deb -O /elasticsearch.deb
RUN dpkg -i /elasticsearch.deb

RUN [ -f "/etc/elasticsearch/elasticsearch.yml.bak" ] || mv /etc/elasticsearch/elasticsearch.yml /etc/elasticsearch/elasticsearch.yml.bak

RUN if [ ! -d "/var/tmp/elasticsearch" ]; then mkdir /var/tmp/elasticsearch; chown elasticsearch:elasticsearch /var/tmp/elasticsearch; fi

ADD es.conf /etc/elasticsearch/elasticsearch.yml

VOLUME /var/tmp/elasticsearch
VOLUME /var/lib/elasticsearch

EXPOSE 9400
EXPOSE 9500

ADD run_es.sh /run_es.sh
RUN chmod 755 /run_es.sh

ENTRYPOINT /run_es.sh 
