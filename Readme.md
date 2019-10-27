# Superdesk Deployment Playbooks

The playbooks are used for deploying Superdesk and Superdesk-Publisher.

There are two use cases defined in them: 

1. Both Publisher and Superdesk on the same VM


2. Separate VMs for Publisher and Superdesk. The database is stored on a 3rd VM.

## Both Publisher and Superdesk on the same VM

The URL used for accessing the Superdesk instance is http://DOMAIN.com/superdesk. Publisher is available at http://DOMAIN.com. Newsroom is available at http://newsroom.DOMAIN.com

### Local installation
The playbook used for local installation is called allinone.yml. A Vagrantfile is available to easily deploy the VM. To deploy the VM use the command 
````vagrant up allinone````, with the current directory set to the location of the Vagrantfile.

The VM will, by default, use the IP address 192.168.13.7 and use the domain name DOMAIN.com. You can change the domain name to another one in the file allinone.yml and the IP address used by the VM in the Vagrantfile.

To be able to access Publisher and Superdesk you will have to add the domain name to your local hosts file, which is at /etc/hosts on Mac and Linux and at C:\Windows\System32\Drivers\etc\hosts in Windows. You will need administrative rights to be able to edit the file. Add the line 
````192.168.13.7 DOMAIN.com```` to the file.

After that you will be able to access Superdesk by accessing the URL http://DOMAIN.com/superdesk. The Publisher instance will be available on http://DOMAIN.com 

To test the API between Superdesk and Publisher, access the Superdesk URL and login as admin with the password admin. You will have to add a first and last name to the user, because Publisher doesn't accept users without them. To do that, click on the menu in the upper left corner, click on "User Management" and edit the admin user.

Testing the API connection is done by clicking on the menu in the upper left corner, selecting "Publisher" and next "Output Settings". You should see the site present there.

### Cloud installation

The cloud installation of Publisher and Superdesk omits installing the packages for the services that are cloudified, like ElasticSearch, MongoDB, etc. It uses the credentials included in the playbook to connect to the cloud services and offer the same service. A Playbook file called allinone_cgp.yml is used for deploying.

The management of the cloudified postgresql database is done in the cloudpg role. It requires two additional variables to be set: postgres_admin and postgres_admin_password. They are used for connecting to the cloud server and creating the database required for development. 

Similarly, cloudifying Redis is done by changing the celery_host variable. When it is different than 'localhost', a local instance of Celery isn't installed. Instead it connects to the remote Celery server described in the celery_host variable at the default port.

## Separate VMs for Publisher and Superdesk. The database is stored on a 3rd VM.

The URL used for accessing the Superdesk instance is http://DOMAIN.com. Publisher is available at http://DOMAIN.com. Newsroom is available at http://newsroom.DOMAIN.com

### Local installation
For local installation three VMs are used:

1. Database VM with Postgresql is defined in playbook db.yml
2. VM with Publisher is defined in wp.yml
3. VM with superdesk is defined in superdesk.yml

With Vagrant deploying them requires running ````vagrant up postgres; vagrant up superdesk1; vagrant up webpublisher1````
