// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bgs/low/pb/client/report_service.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_bgs_2flow_2fpb_2fclient_2freport_5fservice_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_bgs_2flow_2fpb_2fclient_2freport_5fservice_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "bgs/low/pb/client/account_types.pb.h"
#include "bgs/low/pb/client/report_types.pb.h"
#include "bgs/low/pb/client/rpc_types.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_bgs_2flow_2fpb_2fclient_2freport_5fservice_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_bgs_2flow_2fpb_2fclient_2freport_5fservice_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_bgs_2flow_2fpb_2fclient_2freport_5fservice_2eproto;
namespace bgs {
namespace protocol {
namespace report {
namespace v1 {
class SendReportRequest;
class SendReportRequestDefaultTypeInternal;
extern SendReportRequestDefaultTypeInternal _SendReportRequest_default_instance_;
class SubmitReportRequest;
class SubmitReportRequestDefaultTypeInternal;
extern SubmitReportRequestDefaultTypeInternal _SubmitReportRequest_default_instance_;
}  // namespace v1
}  // namespace report
}  // namespace protocol
}  // namespace bgs
PROTOBUF_NAMESPACE_OPEN
template<> ::bgs::protocol::report::v1::SendReportRequest* Arena::CreateMaybeMessage<::bgs::protocol::report::v1::SendReportRequest>(Arena*);
template<> ::bgs::protocol::report::v1::SubmitReportRequest* Arena::CreateMaybeMessage<::bgs::protocol::report::v1::SubmitReportRequest>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace bgs {
namespace protocol {
namespace report {
namespace v1 {

// ===================================================================

class SendReportRequest :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:bgs.protocol.report.v1.SendReportRequest) */ {
 public:
  SendReportRequest();
  virtual ~SendReportRequest();

  SendReportRequest(const SendReportRequest& from);
  SendReportRequest(SendReportRequest&& from) noexcept
    : SendReportRequest() {
    *this = ::std::move(from);
  }

  inline SendReportRequest& operator=(const SendReportRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline SendReportRequest& operator=(SendReportRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const SendReportRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SendReportRequest* internal_default_instance() {
    return reinterpret_cast<const SendReportRequest*>(
               &_SendReportRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SendReportRequest& a, SendReportRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(SendReportRequest* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SendReportRequest* New() const final {
    return CreateMaybeMessage<SendReportRequest>(nullptr);
  }

  SendReportRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SendReportRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SendReportRequest& from);
  void MergeFrom(const SendReportRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SendReportRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "bgs.protocol.report.v1.SendReportRequest";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_bgs_2flow_2fpb_2fclient_2freport_5fservice_2eproto);
    return ::descriptor_table_bgs_2flow_2fpb_2fclient_2freport_5fservice_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kReportFieldNumber = 1,
    kProgramFieldNumber = 2,
  };
  // required .bgs.protocol.report.v1.Report report = 1;
  bool has_report() const;
  private:
  bool _internal_has_report() const;
  public:
  void clear_report();
  const ::bgs::protocol::report::v1::Report& report() const;
  ::bgs::protocol::report::v1::Report* release_report();
  ::bgs::protocol::report::v1::Report* mutable_report();
  void set_allocated_report(::bgs::protocol::report::v1::Report* report);
  private:
  const ::bgs::protocol::report::v1::Report& _internal_report() const;
  ::bgs::protocol::report::v1::Report* _internal_mutable_report();
  public:

  // optional uint32 program = 2;
  bool has_program() const;
  private:
  bool _internal_has_program() const;
  public:
  void clear_program();
  ::PROTOBUF_NAMESPACE_ID::uint32 program() const;
  void set_program(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_program() const;
  void _internal_set_program(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:bgs.protocol.report.v1.SendReportRequest)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::bgs::protocol::report::v1::Report* report_;
  ::PROTOBUF_NAMESPACE_ID::uint32 program_;
  friend struct ::TableStruct_bgs_2flow_2fpb_2fclient_2freport_5fservice_2eproto;
};
// -------------------------------------------------------------------

class SubmitReportRequest :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:bgs.protocol.report.v1.SubmitReportRequest) */ {
 public:
  SubmitReportRequest();
  virtual ~SubmitReportRequest();

  SubmitReportRequest(const SubmitReportRequest& from);
  SubmitReportRequest(SubmitReportRequest&& from) noexcept
    : SubmitReportRequest() {
    *this = ::std::move(from);
  }

  inline SubmitReportRequest& operator=(const SubmitReportRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline SubmitReportRequest& operator=(SubmitReportRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const SubmitReportRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SubmitReportRequest* internal_default_instance() {
    return reinterpret_cast<const SubmitReportRequest*>(
               &_SubmitReportRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(SubmitReportRequest& a, SubmitReportRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(SubmitReportRequest* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SubmitReportRequest* New() const final {
    return CreateMaybeMessage<SubmitReportRequest>(nullptr);
  }

  SubmitReportRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SubmitReportRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SubmitReportRequest& from);
  void MergeFrom(const SubmitReportRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SubmitReportRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "bgs.protocol.report.v1.SubmitReportRequest";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_bgs_2flow_2fpb_2fclient_2freport_5fservice_2eproto);
    return ::descriptor_table_bgs_2flow_2fpb_2fclient_2freport_5fservice_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kAgentIdFieldNumber = 1,
    kReportTypeFieldNumber = 2,
    kProgramFieldNumber = 3,
  };
  // optional .bgs.protocol.account.v1.GameAccountHandle agent_id = 1;
  bool has_agent_id() const;
  private:
  bool _internal_has_agent_id() const;
  public:
  void clear_agent_id();
  const ::bgs::protocol::account::v1::GameAccountHandle& agent_id() const;
  ::bgs::protocol::account::v1::GameAccountHandle* release_agent_id();
  ::bgs::protocol::account::v1::GameAccountHandle* mutable_agent_id();
  void set_allocated_agent_id(::bgs::protocol::account::v1::GameAccountHandle* agent_id);
  private:
  const ::bgs::protocol::account::v1::GameAccountHandle& _internal_agent_id() const;
  ::bgs::protocol::account::v1::GameAccountHandle* _internal_mutable_agent_id();
  public:

  // optional .bgs.protocol.report.v1.ReportType report_type = 2;
  bool has_report_type() const;
  private:
  bool _internal_has_report_type() const;
  public:
  void clear_report_type();
  const ::bgs::protocol::report::v1::ReportType& report_type() const;
  ::bgs::protocol::report::v1::ReportType* release_report_type();
  ::bgs::protocol::report::v1::ReportType* mutable_report_type();
  void set_allocated_report_type(::bgs::protocol::report::v1::ReportType* report_type);
  private:
  const ::bgs::protocol::report::v1::ReportType& _internal_report_type() const;
  ::bgs::protocol::report::v1::ReportType* _internal_mutable_report_type();
  public:

  // optional uint32 program = 3;
  bool has_program() const;
  private:
  bool _internal_has_program() const;
  public:
  void clear_program();
  ::PROTOBUF_NAMESPACE_ID::uint32 program() const;
  void set_program(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_program() const;
  void _internal_set_program(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:bgs.protocol.report.v1.SubmitReportRequest)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::bgs::protocol::account::v1::GameAccountHandle* agent_id_;
  ::bgs::protocol::report::v1::ReportType* report_type_;
  ::PROTOBUF_NAMESPACE_ID::uint32 program_;
  friend struct ::TableStruct_bgs_2flow_2fpb_2fclient_2freport_5fservice_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SendReportRequest

// required .bgs.protocol.report.v1.Report report = 1;
inline bool SendReportRequest::_internal_has_report() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || report_ != nullptr);
  return value;
}
inline bool SendReportRequest::has_report() const {
  return _internal_has_report();
}
inline const ::bgs::protocol::report::v1::Report& SendReportRequest::_internal_report() const {
  const ::bgs::protocol::report::v1::Report* p = report_;
  return p != nullptr ? *p : *reinterpret_cast<const ::bgs::protocol::report::v1::Report*>(
      &::bgs::protocol::report::v1::_Report_default_instance_);
}
inline const ::bgs::protocol::report::v1::Report& SendReportRequest::report() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.report.v1.SendReportRequest.report)
  return _internal_report();
}
inline ::bgs::protocol::report::v1::Report* SendReportRequest::release_report() {
  // @@protoc_insertion_point(field_release:bgs.protocol.report.v1.SendReportRequest.report)
  _has_bits_[0] &= ~0x00000001u;
  ::bgs::protocol::report::v1::Report* temp = report_;
  report_ = nullptr;
  return temp;
}
inline ::bgs::protocol::report::v1::Report* SendReportRequest::_internal_mutable_report() {
  _has_bits_[0] |= 0x00000001u;
  if (report_ == nullptr) {
    auto* p = CreateMaybeMessage<::bgs::protocol::report::v1::Report>(GetArenaNoVirtual());
    report_ = p;
  }
  return report_;
}
inline ::bgs::protocol::report::v1::Report* SendReportRequest::mutable_report() {
  // @@protoc_insertion_point(field_mutable:bgs.protocol.report.v1.SendReportRequest.report)
  return _internal_mutable_report();
}
inline void SendReportRequest::set_allocated_report(::bgs::protocol::report::v1::Report* report) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(report_);
  }
  if (report) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      report = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, report, submessage_arena);
    }
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  report_ = report;
  // @@protoc_insertion_point(field_set_allocated:bgs.protocol.report.v1.SendReportRequest.report)
}

// optional uint32 program = 2;
inline bool SendReportRequest::_internal_has_program() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool SendReportRequest::has_program() const {
  return _internal_has_program();
}
inline void SendReportRequest::clear_program() {
  program_ = 0u;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SendReportRequest::_internal_program() const {
  return program_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SendReportRequest::program() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.report.v1.SendReportRequest.program)
  return _internal_program();
}
inline void SendReportRequest::_internal_set_program(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000002u;
  program_ = value;
}
inline void SendReportRequest::set_program(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_program(value);
  // @@protoc_insertion_point(field_set:bgs.protocol.report.v1.SendReportRequest.program)
}

// -------------------------------------------------------------------

// SubmitReportRequest

// optional .bgs.protocol.account.v1.GameAccountHandle agent_id = 1;
inline bool SubmitReportRequest::_internal_has_agent_id() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || agent_id_ != nullptr);
  return value;
}
inline bool SubmitReportRequest::has_agent_id() const {
  return _internal_has_agent_id();
}
inline const ::bgs::protocol::account::v1::GameAccountHandle& SubmitReportRequest::_internal_agent_id() const {
  const ::bgs::protocol::account::v1::GameAccountHandle* p = agent_id_;
  return p != nullptr ? *p : *reinterpret_cast<const ::bgs::protocol::account::v1::GameAccountHandle*>(
      &::bgs::protocol::account::v1::_GameAccountHandle_default_instance_);
}
inline const ::bgs::protocol::account::v1::GameAccountHandle& SubmitReportRequest::agent_id() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.report.v1.SubmitReportRequest.agent_id)
  return _internal_agent_id();
}
inline ::bgs::protocol::account::v1::GameAccountHandle* SubmitReportRequest::release_agent_id() {
  // @@protoc_insertion_point(field_release:bgs.protocol.report.v1.SubmitReportRequest.agent_id)
  _has_bits_[0] &= ~0x00000001u;
  ::bgs::protocol::account::v1::GameAccountHandle* temp = agent_id_;
  agent_id_ = nullptr;
  return temp;
}
inline ::bgs::protocol::account::v1::GameAccountHandle* SubmitReportRequest::_internal_mutable_agent_id() {
  _has_bits_[0] |= 0x00000001u;
  if (agent_id_ == nullptr) {
    auto* p = CreateMaybeMessage<::bgs::protocol::account::v1::GameAccountHandle>(GetArenaNoVirtual());
    agent_id_ = p;
  }
  return agent_id_;
}
inline ::bgs::protocol::account::v1::GameAccountHandle* SubmitReportRequest::mutable_agent_id() {
  // @@protoc_insertion_point(field_mutable:bgs.protocol.report.v1.SubmitReportRequest.agent_id)
  return _internal_mutable_agent_id();
}
inline void SubmitReportRequest::set_allocated_agent_id(::bgs::protocol::account::v1::GameAccountHandle* agent_id) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(agent_id_);
  }
  if (agent_id) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      agent_id = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, agent_id, submessage_arena);
    }
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  agent_id_ = agent_id;
  // @@protoc_insertion_point(field_set_allocated:bgs.protocol.report.v1.SubmitReportRequest.agent_id)
}

// optional .bgs.protocol.report.v1.ReportType report_type = 2;
inline bool SubmitReportRequest::_internal_has_report_type() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || report_type_ != nullptr);
  return value;
}
inline bool SubmitReportRequest::has_report_type() const {
  return _internal_has_report_type();
}
inline const ::bgs::protocol::report::v1::ReportType& SubmitReportRequest::_internal_report_type() const {
  const ::bgs::protocol::report::v1::ReportType* p = report_type_;
  return p != nullptr ? *p : *reinterpret_cast<const ::bgs::protocol::report::v1::ReportType*>(
      &::bgs::protocol::report::v1::_ReportType_default_instance_);
}
inline const ::bgs::protocol::report::v1::ReportType& SubmitReportRequest::report_type() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.report.v1.SubmitReportRequest.report_type)
  return _internal_report_type();
}
inline ::bgs::protocol::report::v1::ReportType* SubmitReportRequest::release_report_type() {
  // @@protoc_insertion_point(field_release:bgs.protocol.report.v1.SubmitReportRequest.report_type)
  _has_bits_[0] &= ~0x00000002u;
  ::bgs::protocol::report::v1::ReportType* temp = report_type_;
  report_type_ = nullptr;
  return temp;
}
inline ::bgs::protocol::report::v1::ReportType* SubmitReportRequest::_internal_mutable_report_type() {
  _has_bits_[0] |= 0x00000002u;
  if (report_type_ == nullptr) {
    auto* p = CreateMaybeMessage<::bgs::protocol::report::v1::ReportType>(GetArenaNoVirtual());
    report_type_ = p;
  }
  return report_type_;
}
inline ::bgs::protocol::report::v1::ReportType* SubmitReportRequest::mutable_report_type() {
  // @@protoc_insertion_point(field_mutable:bgs.protocol.report.v1.SubmitReportRequest.report_type)
  return _internal_mutable_report_type();
}
inline void SubmitReportRequest::set_allocated_report_type(::bgs::protocol::report::v1::ReportType* report_type) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(report_type_);
  }
  if (report_type) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      report_type = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, report_type, submessage_arena);
    }
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  report_type_ = report_type;
  // @@protoc_insertion_point(field_set_allocated:bgs.protocol.report.v1.SubmitReportRequest.report_type)
}

// optional uint32 program = 3;
inline bool SubmitReportRequest::_internal_has_program() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool SubmitReportRequest::has_program() const {
  return _internal_has_program();
}
inline void SubmitReportRequest::clear_program() {
  program_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SubmitReportRequest::_internal_program() const {
  return program_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SubmitReportRequest::program() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.report.v1.SubmitReportRequest.program)
  return _internal_program();
}
inline void SubmitReportRequest::_internal_set_program(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000004u;
  program_ = value;
}
inline void SubmitReportRequest::set_program(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_program(value);
  // @@protoc_insertion_point(field_set:bgs.protocol.report.v1.SubmitReportRequest.program)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace report
}  // namespace protocol
}  // namespace bgs

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_bgs_2flow_2fpb_2fclient_2freport_5fservice_2eproto
