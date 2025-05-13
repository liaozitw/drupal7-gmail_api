# 📬 Gmail API for Drupal 7

使用 Gmail API 完整取代 Drupal 7 全站的寄信功能，支援 HTML 郵件、自動 Refresh Token、後台授權與測試。

## 功能特色

- ✅ 使用 Gmail API 寄送 Email（不再使用 `mail()` 或 SMTP）
- ✅ 支援 HTML 郵件內容
- ✅ Access Token 儲存於 Drupal 系統設定（`variable`）
- ✅ 自動 refresh token，不需重新授權
- ✅ 可取代 Drupal 全站寄信（註冊、聯絡表單等）
- ✅ 提供後台測試寄信功能
- ✅ 中文主旨正確編碼（無亂碼）

## 安裝方式

1. 將此模組放入 `sites/all/modules/gmail_api/`
2. 使用 Composer 安裝 Gmail API PHP 套件：

```bash
composer require google/apiclient:^1.1
```

## Google API 設定

1. 前往 Google Cloud Console
2. 建立專案並啟用 Gmail API
3. 建立 OAuth 憑證，設定 redirect URI 為：
https://your-site.com/gmail-api/oauth2callback

4. 複製 Client ID / Secret，填入 Drupal 後台

## 後台操作
- 設定頁面：/admin/config/services/gmail-api
- 測試寄信：/admin/config/services/gmail-api/test
- 完成授權後，系統所有信件皆經 Gmail API 發送 (授權時會登入Google帳號驗證，必須使用與設定 Gmail API相同的帳號，驗證過程有時會出錯，建議多試幾次)

## 自動使用系統寄信
模組會使用 hook_mail_alter()：
- ✅ 替換系統所有 drupal_mail() 信件
- ✅ 發送 HTML 郵件
- ✅ 正確處理中文主旨編碼
- ✅ 自動 refresh access token

## 授權與貢獻
- 授權：MIT
- 作者：台南意向 & ChatGPT & Grok
