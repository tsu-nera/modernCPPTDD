CPP_COMPILER = "/opt/centos/devtoolset-1.1/root/usr/bin/g++"
TARGET="moderncpp.exe"
GMOCK_HOME="/home/tsu-nera/tools/gmock"
INC_DIR="-I#{GMOCK_HOME}/include -I#{GMOCK_HOME}/gtest/include"
LIB_DIR="-L#{GMOCK_HOME}/mybuild -L#{GMOCK_HOME}/gtest/mybuild" 
LIB="-lpthread -lgtest -lgmock"

require 'rake/clean'
CLEAN.include(["src/*.o", "*.exe"])
#CLOBBER.include("*.exe")

desc "Clean and Run"
task :all => ["clean", "run"]

desc "Run build"
task :default => "run"

desc "Build Main"
task :run => TARGET do
  puts "---- run  ----"
  sh "./#{TARGET}"
end

SRCS = FileList["main.cpp","c2/*.cpp", "c3/*.cpp"]
OBJS = SRCS.ext('o')

file TARGET => OBJS do |t|
  puts "---- link ----"
  sh "#{CPP_COMPILER} -o #{t.name} #{t.prerequisites.join(' ')} #{LIB_DIR} #{LIB}"
end

rule '.o' => '.cpp' do |t|
  puts "---- compile ----"
  sh "#{CPP_COMPILER} -Wall -std=c++0x #{INC_DIR} -c #{t.source} -o #{t.name}"
end
