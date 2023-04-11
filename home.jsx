import useDocusaurusContext from '@docusaurus/useDocusaurusContext';

export default function Home() {
  const {
    siteConfig: {customFields},
  } = useDocusaurusContext();
  return <div>Contact us through {customFields.teamEmail}!</div>;
}