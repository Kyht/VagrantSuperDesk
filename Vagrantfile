Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/bionic64"
  
  config.vm.define "postgres" do |postgres|
    postgres.vm.network "private_network", ip: "192.168.13.4"
    
    postgres.vm.provider "virtualbox" do |v|
      v.memory = 512
      v.cpus = 1
    end

    postgres.vm.provision "ansible" do |ansible|
      ansible.playbook = "db.yml"
      ansible.extra_vars = { ansible_python_interpreter:"/usr/bin/python3" }
      #    ansible.groups = {
      #      "databases" => ["postgres"],
      #      "newsrooms" => ["newsroom1"],
      #      "webpublishers" => ["webpublisher1"],
      #    }
      ansible.become = true
    end
  end
   
  config.vm.define "superdesk1" do |superdesk1|
   superdesk1.vm.network "private_network", ip: "192.168.13.5"

    superdesk1.vm.provider "virtualbox" do |v|
      v.memory = 3072
      v.cpus = 1
    end
    superdesk1.vm.provision "ansible" do |ansible|
      ansible.playbook = "superdesk.yml"
      ansible.extra_vars = { ansible_python_interpreter:"/usr/bin/python3" }
#      #    ansible.groups = {
#      #      "databases" => ["postgres"],
#      #      "newsrooms" => ["newsroom1"],
#      #      "webpublishers" => ["webpublisher1"],
#      #    }
      ansible.become = true
      ansible.verbose = true
    end
#   superdesk1.vm.provision "shell", path: "superdesk-install.sh"
 end
  
  config.vm.define "webpublisher1" do |webpublisher|
    webpublisher.vm.network "private_network", ip: "192.168.13.6"
    
    webpublisher.vm.provider "virtualbox" do |v|
      v.memory = 2048
      v.cpus = 1
    end

    webpublisher.vm.provision "ansible" do |ansible|
      ansible.playbook = "wp.yml"
      ansible.extra_vars = { ansible_python_interpreter:"/usr/bin/python3" }
      #    ansible.groups = {
      #      "databases" => ["postgres"],
      #      "newsrooms" => ["newsroom1"],
      #      "webpublishers" => ["webpublisher1"],
      #    }
      ansible.become = true
      ansible.verbose = true
    end
  end
  
  config.vm.define "allinone" do |allinone|
   allinone.vm.network "private_network", ip: "192.168.13.7"

    allinone.vm.provider "virtualbox" do |v|
      v.memory =   5120
      v.cpus = 1
    end
    allinone.vm.provision "ansible" do |ansible|
      ansible.playbook = "allinone.yml"
      ansible.extra_vars = { ansible_python_interpreter:"/usr/bin/python3" }
#      #    ansible.groups = {
#      #      "databases" => ["postgres"],
#      #      "newsrooms" => ["newsroom1"],
#      #      "webpublishers" => ["webpublisher1"],
#      #    }
      ansible.become = true
      ansible.verbose = true
    end
 end

end
