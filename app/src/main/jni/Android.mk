# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES +=  $(LOCAL_PATH)/includes/ \
                    	$(LOCAL_PATH)/includes/expat/ \
                    	$(LOCAL_PATH)/includes/scew/ \
$(LOCAL_PATH)/SmartSlog/

LOCAL_MODULE    := hello-jni
LOCAL_SRC_FILES := hello-jni.c \
hello.c \
SmartSlog/triple.c \
SmartSlog/session.c \
SmartSlog/subscription_changes.c \
SmartSlog/high_api.c \
SmartSlog/entity.c \
SmartSlog/scew/error.c \
SmartSlog/scew/str.c \
SmartSlog/scew/writer.c \
SmartSlog/scew/printer.c \
SmartSlog/scew/xparser.c \
SmartSlog/scew/element_compare.c \
SmartSlog/scew/element_search.c \
SmartSlog/scew/reader_file.c \
SmartSlog/scew/attribute.c \
SmartSlog/scew/writer_file.c \
SmartSlog/scew/reader_buffer.c \
SmartSlog/scew/element.c \
SmartSlog/scew/list.c \
SmartSlog/scew/reader.c \
SmartSlog/scew/xattribute.c \
SmartSlog/scew/element_attribute.c \
SmartSlog/scew/element_copy.c \
SmartSlog/scew/tree.c \
SmartSlog/scew/parser.c \
SmartSlog/scew/xerror.c \
SmartSlog/scew/writer_buffer.c \
SmartSlog/triplestore.c \
SmartSlog/kpi_interface.c \
SmartSlog/ckpi/sskp_errno.c \
SmartSlog/ckpi/process_ssap_cnf.c \
SmartSlog/ckpi/compose_ssap_msg.c \
SmartSlog/ckpi/parse_ssap_msg.c \
SmartSlog/ckpi/ckpi.c \
SmartSlog/ckpi/sib_access_tcp.c \
SmartSlog/subscription.c \
SmartSlog/utils/list.c \
SmartSlog/utils/util_func.c \
SmartSlog/utils/errors.c \
SmartSlog/expat/xmlrole.c \
SmartSlog/expat/xmlparse.c \
SmartSlog/expat/xmltok_impl.c \
SmartSlog/expat/xmltok_ns.c \
SmartSlog/expat/xmltok.c \
SmartSlog/kpi_api.c \
SmartSlog/property_changes.c \


LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog
LOCAL_SHARED_LIBRARIES += liblog
LOCAL_CFLAGS := -std=c99 -DMTENABLE -DHAVE_EXPAT_CONFIG_H -DHAVE_MEMMOVE

include $(BUILD_SHARED_LIBRARY)