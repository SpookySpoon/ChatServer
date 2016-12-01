// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messageformat.proto

#ifndef PROTOBUF_messageformat_2eproto__INCLUDED
#define PROTOBUF_messageformat_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace chatMes {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_messageformat_2eproto();
void protobuf_AssignDesc_messageformat_2eproto();
void protobuf_ShutdownFile_messageformat_2eproto();

class hello;

// ===================================================================

class hello : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:chatMes.hello) */ {
 public:
  hello();
  virtual ~hello();

  hello(const hello& from);

  inline hello& operator=(const hello& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const hello& default_instance();

  void Swap(hello* other);

  // implements Message ----------------------------------------------

  inline hello* New() const { return New(NULL); }

  hello* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const hello& from);
  void MergeFrom(const hello& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(hello* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string mesText = 1;
  void clear_mestext();
  static const int kMesTextFieldNumber = 1;
  const ::std::string& mestext() const;
  void set_mestext(const ::std::string& value);
  void set_mestext(const char* value);
  void set_mestext(const char* value, size_t size);
  ::std::string* mutable_mestext();
  ::std::string* release_mestext();
  void set_allocated_mestext(::std::string* mestext);

  // optional uint64 dateTime = 2;
  void clear_datetime();
  static const int kDateTimeFieldNumber = 2;
  ::google::protobuf::uint64 datetime() const;
  void set_datetime(::google::protobuf::uint64 value);

  // optional string nickName = 3;
  void clear_nickname();
  static const int kNickNameFieldNumber = 3;
  const ::std::string& nickname() const;
  void set_nickname(const ::std::string& value);
  void set_nickname(const char* value);
  void set_nickname(const char* value, size_t size);
  ::std::string* mutable_nickname();
  ::std::string* release_nickname();
  void set_allocated_nickname(::std::string* nickname);

  // @@protoc_insertion_point(class_scope:chatMes.hello)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr mestext_;
  ::google::protobuf::uint64 datetime_;
  ::google::protobuf::internal::ArenaStringPtr nickname_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_messageformat_2eproto();
  friend void protobuf_AssignDesc_messageformat_2eproto();
  friend void protobuf_ShutdownFile_messageformat_2eproto();

  void InitAsDefaultInstance();
  static hello* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// hello

// optional string mesText = 1;
inline void hello::clear_mestext() {
  mestext_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& hello::mestext() const {
  // @@protoc_insertion_point(field_get:chatMes.hello.mesText)
  return mestext_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void hello::set_mestext(const ::std::string& value) {
  
  mestext_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chatMes.hello.mesText)
}
inline void hello::set_mestext(const char* value) {
  
  mestext_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chatMes.hello.mesText)
}
inline void hello::set_mestext(const char* value, size_t size) {
  
  mestext_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chatMes.hello.mesText)
}
inline ::std::string* hello::mutable_mestext() {
  
  // @@protoc_insertion_point(field_mutable:chatMes.hello.mesText)
  return mestext_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* hello::release_mestext() {
  // @@protoc_insertion_point(field_release:chatMes.hello.mesText)
  
  return mestext_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void hello::set_allocated_mestext(::std::string* mestext) {
  if (mestext != NULL) {
    
  } else {
    
  }
  mestext_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), mestext);
  // @@protoc_insertion_point(field_set_allocated:chatMes.hello.mesText)
}

// optional uint64 dateTime = 2;
inline void hello::clear_datetime() {
  datetime_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 hello::datetime() const {
  // @@protoc_insertion_point(field_get:chatMes.hello.dateTime)
  return datetime_;
}
inline void hello::set_datetime(::google::protobuf::uint64 value) {
  
  datetime_ = value;
  // @@protoc_insertion_point(field_set:chatMes.hello.dateTime)
}

// optional string nickName = 3;
inline void hello::clear_nickname() {
  nickname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& hello::nickname() const {
  // @@protoc_insertion_point(field_get:chatMes.hello.nickName)
  return nickname_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void hello::set_nickname(const ::std::string& value) {
  
  nickname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chatMes.hello.nickName)
}
inline void hello::set_nickname(const char* value) {
  
  nickname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chatMes.hello.nickName)
}
inline void hello::set_nickname(const char* value, size_t size) {
  
  nickname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chatMes.hello.nickName)
}
inline ::std::string* hello::mutable_nickname() {
  
  // @@protoc_insertion_point(field_mutable:chatMes.hello.nickName)
  return nickname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* hello::release_nickname() {
  // @@protoc_insertion_point(field_release:chatMes.hello.nickName)
  
  return nickname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void hello::set_allocated_nickname(::std::string* nickname) {
  if (nickname != NULL) {
    
  } else {
    
  }
  nickname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), nickname);
  // @@protoc_insertion_point(field_set_allocated:chatMes.hello.nickName)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace chatMes

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_messageformat_2eproto__INCLUDED
